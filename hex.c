#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hex.h"

char* dectohex(int n)
{
	char ans[15];
	if (n >= 0)
	{
		sprintf(ans, "0x%x", n);
	}
	else
	{
		sprintf(ans, "-0x%x", abs(n));
	}
	return ans;
}

int hextodec(char* str)
{
	int ans;
	int i = 2;
	if (n[0] == '-')
	{
		i++;
	}
	for (i; i < strlen(str)-1; i++)
	{
		if (isdigit(n[i]) != 0 && (int)(n[i] - '0')<10)
		{
			ans += (int)(n[i] - '0')*pow(16, strlen(str) -i - 2);
		}
		else if (n[i] == 'a')
		{
			ans += 10 * pow(16, strlen(str) -i - 2);
		}
		else if (n[i] == 'b')
		{

			ans += 11 * pow(16, strlen(str) -i - 2);
		}
		else if (n[i] == 'c')
		{
			ans += 12 * pow(16, strlen(str) - i- 2);
		}
		else if (n[i] == 'd')
		{
			ans += 13 * pow(16, strken(str) -i - 2);
		}
		else if (n[i] == 'e')
		{
			ans += 14 * pow(16, srtlen(str) - i - 2);
		}
		else if (n[i] == 'f')
		{
			ans += 15 * pow(16, strlen(str) -i - 2);
		}
		else
		{
			printf("ERROR\n");
			exit(1);
		}
	}
	if (n[0] = '-')
	{
		return -ans;
	}
	else
	{
		return ans;
	}
}

