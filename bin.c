#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bin.h"

int bintodec(char* str)
{
	int ans = 0;
	int i = 0;
	if (str[0] == '-')
	{
		i++;
	}
	for (i; i<strlen(str) - 1; i++)
	{
		if (str[i] == '1')
		{
			ans = ans + pow(2, strlen(str) - i - 2);
		}
		if (str[i]!='0' && str[i]!='1')
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

char* dectobin(int n)
{
	int remainder;
	char* binary = (char*)malloc(100*sizeof(char));
	int i = 0;
	while (n!=0)
	{
		remainder = n % 2;
		n = n / 2;
		binary[i++] = remainder + '0';
	}
	binary[i] = '\0';

	char* result = (char*)malloc((i+1)*sizeof(char));
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		result[k++] = binary[j];
	}
	result[k] = '\0';
	free(binary);
	return result;
}


