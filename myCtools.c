//my C tools
#include"myCtools.h"
#include<stdlib.h>
#include<stdarg.h>

void *safe_calloc(size_t n, size_t size)
{
	void *ret;
	if ((ret=calloc(n, size)) == NULL)
		panic_errno("calloc() Failed");
	return ret;
}

void *safe_malloc(size_t size)
{
	void *ret;
	if ((ret=malloc(size)) == NULL)
		panic_errno("malloc() Failed");
	return ret;
}

void panicf_errno(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	fflush(stdout);
	perror("");
	va_end(args);
	exit(1);
}

void panic_errno(const char *s)
{
	perror(s);
	exit(1);
}

void panicf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	fflush(stdout);
	va_end(args);
	exit(1);
}

void panic(const char *s)
{
	fputs(s, stderr);
	putc('\n', stderr);
	exit(1);
}

FILE *safe_fopen(const char *path, const char *mode)
{
	FILE *pfile;
	if ((pfile = fopen(path, mode)) == NULL)
		panicf_errno("Can't open %s\n",path);
	return pfile;
}

int get_num(FILE *pfile)
{
	int ret;
	if (fscanf(pfile, "%d", &ret) != 1)
		panic("Can't read a number.\n");
	return ret;
}

void check_argc(int real_argc, int wanted_argc, const char *tip)
{
	if (real_argc != wanted_argc)
	{
		fputs(tip, stderr);
		exit(2);
	}
}

void clear_stdin(void)
{
	/*
	#ifdef __ANDROID__
		fpurge(stdin);
	#endif
	#ifndef __ANDROID__
		#ifdef linux
		__fpurge(stdin);
		#endif
	#endif
	*/
	int ch;
	while((ch=getchar()) == '\n' || ch == EOF);
}
