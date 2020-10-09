				// libadd.c
#include "libadd.h"
#include "myCtools.h"
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define ERR_INPUT "A non-digit charactor is found in the parameters."
	_Bool carry_flag;
static char add_byte(char, char);
static char numtochar(char);
static char chartonum(char);
void check_argv(char *argv[])
{
	int len = strlen(argv[1]), i;

	for (i = 0; i < len; i++)
	{
		if (!isdigit(argv[1][i]))
			panic(ERR_INPUT);
	}
	len = strlen(argv[2]);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(argv[2][i]))
			panic(ERR_INPUT);
	}
	return;
}

char *bignumadd(const char *n1, const char *n2)
{
	int len1, len2, i = 0, j, maxlen, minlen;
	char *ans, *temp;
	const char *maxnum, *minnum;

	len1 = strlen(n1);
	while (n1[i++] == '0' && i < len1);		// skip forward 0s
	len1 = strlen(n1 += i - 1);
	i = 0;
	len2 = strlen(n2);
	while (n2[i++] == '0' && i < len2);
	len2 = strlen(n2 += i - 1);

	if (len1 > len2)
	{
		maxlen = strlen(maxnum = n1);
		minlen = strlen(minnum = n2);
	}
	else
	{
		maxlen = strlen(maxnum = n2);
		minlen = strlen(minnum = n1);
	}
	ans = (char *)safe_calloc(maxlen + 2, sizeof(char));
	memcpy(ans + 1, maxnum, maxlen);
	for (i = minlen, j = maxlen; i != 0; i--, j--)
		ans[j] = add_byte(ans[j], minnum[i - 1]);
	if (carry_flag)
	{
		ans[0] = '1';
	}
	else
	{
		memmove(ans, ans + 1, maxlen);
		if ((temp = realloc(ans, maxlen + 1)))  // Try to realloc it carefully
			ans = temp;
		ans[maxlen] = '\0';
	}
	return ans;
}

static char add_byte(char a, char b)
{
	char ans, x, y;
	x = chartonum(a);
	y = chartonum(b);
	ans = x + y + carry_flag;
	if (ans > 9)
	{
		ans -= 10;
		carry_flag = 1;
	}
	else
		carry_flag = 0;
	ans = numtochar(ans);
	return ans;
}

static char chartonum(char a)
{
	char ret;
	switch (a)
	{
	case '0':
		ret = 0;
		break;
	case '1':
		ret = 1;
		break;
	case '2':
		ret = 2;
		break;
	case '3':
		ret = 3;
		break;
	case '4':
		ret = 4;
		break;
	case '5':
		ret = 5;
		break;
	case '6':
		ret = 6;
		break;
	case '7':
		ret = 7;
		break;
	case '8':
		ret = 8;
		break;
	case '9':
		ret = 9;
		break;
	default:
		panic("Internal Error.");
	}
	return ret;
}

static char numtochar(char num)
{
	static char table[10] = {
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9'
	};
	if (num > 9 || num < 0)
		panic("Internal Error.");
	return table[(int) num];
}
