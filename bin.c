#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bin.h"

int bintodec(char* str)
{
	int ans = 0;
	if (strlen(str) == 2 && str[0] == '0')
	{
		return 0;
	}

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

/*char* dectobin(int n)
{
	int remainder;
	char* binary = (char*)malloc(100*sizeof(char));
	int i = 0;
	if (n == 0)
	{
		return '0';
	}8
	else
	{
	while (n!=0)
	{
		remainder = n % 2;
		n = n / 2;
		binary[i++] =(char)remainder;
	}

	char* result = (char*)malloc((i+1)*sizeof(char));
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		result[k++] = binary[j];
	}
	free(binary);
	return result;
	
}*/

char* dectobin(int n) {
    int flag = 0;
    if (n < 0)
    {
        flag = 1;
        n = abs(n);
    }
    else if(n == 0)
    {
	    return "0";
    }

    char *binary = (char *)malloc(32 * sizeof(char));
    int i = 0;
    while (n > 0) {
        binary[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }
    int indexx = strlen(binary);
    binary[i] = '\0';
    if (flag == 1)
	{
		binary[indexx] = '-';
		binary[indexx + 1] = '\0';
		indexx++;
	}
	else
	{
		binary[indexx] = '\0';
	}
	int start = 0;
	int end = indexx - 1;
	while (start < end)
	{
		char temp = binary[start];
		binary[start] = binary[end];
		binary[end] = temp;
		start++;
		end--;
	}

    return binary;
}


