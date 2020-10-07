//Big number add
//Usage: add %1 %2
#include "myCtools.h"
#include "libadd.h"
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *ans;
	if (argc != 3)
		panicf("Usage: %s num1 num2\n", argv[0]);
	check_argv(argv);
	ans=bignumadd(argv[1], argv[2]);
	puts(ans);
	free(ans);
	return 0;
}