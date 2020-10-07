#include<stdio.h>
void *safe_malloc(size_t);
void *safe_calloc(size_t, size_t);
void panicf_errno(const char *, ...);
void panic_errno(const char *);
void panicf(const char *, ...);
void panic(const char *);
FILE *safe_fopen(const char *, const char *); //panic if failed
int get_num(FILE *); //panic if failed
void check_argc(int, int, const char *); //panic if not equal, arg3 is output.
void clear_stdin(void); //clear stdin buffer