#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "oct.h"
#include <ctype.h>


int octtodec(char* str)
{
	int ans = 0;
	int i = 1;
	if (str[0] == '-')
	{
		i+=1;
	}
	for (i; i<strlen(str)-1;i++)
	{
		if (isdigit(str[i])!=0 && (int)(str[i] - '0') < 8)
		{
			ans += (int)(str[i] - '0')*pow(8, strlen(str) - 2 - i);
		}
		else
		{
			printf("WRONG TYPE\n");
			exit(0);
		}
	}
	if (str[0] == '-')
	{
		return -ans;
	}
	else
	{
		return ans;
	}
}

char* dectooct(int n)
{
	char* ans = (char*)malloc(32);
	if (n >= 0)
	{
		sprintf(ans, "0%o", n);
	}
	else
	{
		sprintf(ans, "-0%o", abs(n));
	}
	return ans;
}


