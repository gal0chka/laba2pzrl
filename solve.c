#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solve.h"

int findtype(char* n)
{
	if (n[0] = '-')
	{
		n = n + 1;//сдвигаем
	}
	if (n[0] == '0' && strlen(n)= 2)
	{
		return 0;//в двоичной 0
	}
	if (n[0] == '0' && strlen(n)>2)
	{
		return 1;//восьмеричная
	}
	if (n[0] == '0' && n[1] == 'x')
	{
		return 2;//шестандцатиричная
	}
	else
	{
		return 0;//двоичная
	}


int summa(int num1, int num2)
{
	return num1 + num2;
}

int minus(int num1, int num2)
{
	return num1 - num2;
}

int multiplication(int num1, int num2)
{
	return num1 * num2;
}

int percent(int num1, int num2)
{
	return num1 % num2;
}

int bin_and(int num1, int num2)
{
	return num1 & num2;
}

int bin_or(int num1, int num2)
{
	return num1 | num2;
}

int XOR(int num1, int num2)
{
	return num1 ^ num2;
}

int tilda(int num)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return -(n + 1);
	}
}



