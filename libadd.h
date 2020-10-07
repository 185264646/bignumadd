// libadd.h, a library file for bignumadd.c

void check_argv(char *[]);
/*
	Check whether the argv is valid or not.
	Terminate the program if the argument is invalid.
*/

char *bignumadd(const char *, const char *);
/*
	Add two parameters and return the address of the result.
	Terminate the program if internal error occurs.
*/