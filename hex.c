#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hex.h"

char* dectohex(int n)
{
	char* ans = (char*)malloc(32);
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
	int ans = 0;
	int i = 2;
	//printf("%s\n", str);
	if (str[0] == '-')
	{
		i += 1;
	}
	for (i; i < strlen(str)-1; i++)
	{
		if (isdigit(str[i]) != 0 && (int)(str[i] - '0')<10)
		{
			ans += (int)(str[i] - '0')*pow(16, strlen(str) - i - 2);
		}
		else if (str[i] == 'a')
		{
			ans += 10 * pow(16, strlen(str) -i - 2);
		}
		else if (str[i] == 'b')
		{

			ans += 11 * pow(16, strlen(str) -i - 2);
		} 
		else if (str[i] == 'c')
		{
			ans += 12 * pow(16, strlen(str) - i- 2);
		}
		else if (str[i] == 'd')
		{
			ans += 13 * pow(16, strlen(str) -i - 2);
		}
		else if (str[i] == 'e')
		{
			ans += 14 * pow(16, strlen(str) - i - 2);
		}
		else if (str[i] == 'f')
		{
			ans += 15 * pow(16, strlen(str) -i - 2);
		}
		else
		{
			printf("ERROR\n");
			exit(0);
		}
	}
	if (str[0] == '-')
	{
		//printf("%i\n", -ans);
		return -ans;
	}
	else
	{
		//printf("%i\n", ans);
		return ans;
	}
}

