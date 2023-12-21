#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"
#include "solve.h"

void main()
{
	char* str = NULL;
	char* num1 = NULL;
	char* num2 = NULL;
	char* oper = NULL;
	char* bin = NULL;
	char* oct = NULL;
	char* hex = NULL;
	size_t len = 0;
	getline(&str, &len, stdin);
	if (strchr(str, '~') != NULL)
	{
		num1 = str + 1;
		if (findtype(num1) == 0)
		{
			bin = dectobin(tilda(bintodec(num1)));
			printf("%s \t (%i)\n", bin, tilda(bintodec(num1)));
			free(bin);
		}
		else if (findtype(num1) == 1)
		{
			oct = dectooct(tilda(octtodec(num1)));
			printf("%s \t (%i)\n", oct, tilda(octtodec(num1)));
			free(oct);
		}
		else
		{
			hex = dectohex(tilda(hextodec(num1)));
			printf("%s \t (%i)\n", hex, tilda(hextodec(num1)));
			free(hex);
		}
		free(str);
		exit(0);
	}
	char num1_b[50];
	char oper_b[2];
	char num2_b[50];
	sscanf(str, "%49s %1s %49s", num1_b, oper_b, num2_b);
	num1 = strdup(num1_b);
	oper = strdup(oper_b);
	num2 = strdup(num2_b);
	size_t len1 = strlen(num1);
	size_t len2 = strlen(num2);
	char* new_str1 = (char*)malloc(len1+2);
	char* new_str2 = (char*)malloc(len2+2);
	strcpy(new_str1, num1);
	strcpy(new_str2, num2);
	new_str1[len1] = '0';
	new_str2[len2] = '0';
	free(num1);
	free(num2);
	num1 = new_str1;
	num2 = new_str2;
	//printf("%s\n", oper);
	//printf("%s   %s\n",  num1, num2);
	if (findtype(num1) != findtype(num2))
	{
		printf("TYPE ERROR\n");
		free(str);
		free(num1);
		free(num2);
		free(oper);
		exit(0);
	}
	if (*oper == '+')
	{
		if (findtype(num1) == 0)
		{
			bin = dectobin(summa(bintodec(num1), bintodec(num2)));
			//printf("%s %i\n", bin, 1111111);
			printf("%s \t (%i)\n", bin, summa(bintodec(num1),bintodec(num2)));
			free(bin);
		}
		else if (findtype(num1) == 1)
		{
			oct = dectooct(summa(octtodec(num1), octtodec(num2)));
			printf("%s \t (%i)\n", oct, summa(octtodec(num1), octtodec(num2)));
			free(oct);
		}
		else if (findtype(num1) == 2)
		{
			hex = dectohex(summa(hextodec(num1), hextodec(num2)));
			printf("%s \t (%i)\n", hex, summa(hextodec(num1), hextodec(num2)));
			free(hex);
		}
	}
	else if (*oper == '-')
	{
		if (findtype(num1) == 0)
		{
			bin = dectobin(minus(bintodec(num1), bintodec(num2)));
			printf("%s \t (%i)\n", bin, minus(bintodec(num1), bintodec(num2)));
			free(bin);
		}
		else if (findtype(num1) == 1)
		{
			oct = dectooct(minus(octtodec(num1), octtodec(num2)));
			printf("%s \t (%i)\n", oct, minus(octtodec(num1), octtodec(num2)));
			free(oct);
		}
		else if(findtype(num1) == 2)
		{
			hex = dectohex(minus(hextodec(num1), hextodec(num2)));
			printf("%s \t (%i)\n", hex, minus(hextodec(num1), hextodec(num2)));
			free(hex);
		}
	}
	else if (*oper == '*')
	{
		if (findtype(num1) == 0)
		{
			bin = dectobin(multiplication(bintodec(num1), bintodec(num2)));
			printf("%s \t (%i)\n", bin, multiplication(bintodec(num1), bintodec(num2)));
			free(bin);
		}
		else if (findtype(num1) == 1)
		{
			oct = dectooct(multiplication(octtodec(num1), octtodec(num2)));
			printf("%s \t (%i)\n", oct, multiplication(octtodec(num1), octtodec(num2)));
			free(oct);
		}
		else if(findtype(num1)==2)
		{
			hex = dectohex(multiplication(hextodec(num1), hextodec(num2)));
			printf("%s \t (%i)\n", hex, multiplication(hextodec(num1), hextodec(num2)));
			free(hex);
		}
	}
	else if (*oper == '%')
	{
		if (findtype(num1) == 0)
		{
			bin = dectobin(percent(bintodec(num1), bintodec(num2)));
			printf("%s \t (%i)\n", bin, percent(bintodec(num1), bintodec(num2)));
			free(bin);
		}
		else if (findtype(num1) == 1)
		{
			oct = dectooct(percent(octtodec(num1), octtodec(num2)));
			printf("%s \t (%i)\n", oct, percent(octtodec(num1), octtodec(num2)));
			free(oct);
		}
		else if(findtype(num1)==2)
		{
			hex = dectohex(percent(hextodec(num1), hextodec(num2)));
			printf("%s \t (%i)\n", hex, percent(hextodec(num1), hextodec(num2)));
			free(hex);
		}
	}
	else if (*oper == '&')
	{
		if (num1[0]!='-' && num2[0] != '-')
		{

			if (findtype(num1) == 0)
			{
				bin = dectobin(multiplication(bintodec(num1), bintodec(num2)));
				printf("%s \t (%i)\n", bin, multiplication(bintodec(num1), bintodec(num2)));
				free(bin);
			}
			else if (findtype(num1) == 1)
			{
				oct = dectooct(multiplication(octtodec(num1), octtodec(num2)));
				printf("%s \t (%i)\n", oct, multiplication(octtodec(num1), octtodec(num2)));
				free(oct);
			}
			else if(findtype(num1)==2)
			{
				hex = dectohex(multiplication(hextodec(num1), hextodec(num2)));
				printf("%s \t (%i)\n", hex, multiplication(hextodec(num1), hextodec(num2)));
				free(hex);
			}
		}
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*oper == '|')
	{
		if (num1[0]!='-' && num2[0] != '-')
		{

			if (findtype(num1) == 0)
			{
				bin = dectobin(multiplication(bintodec(num1), bintodec(num2)));
				printf("%s \t (%i)\n", bin, multiplication(bintodec(num1), bintodec(num2)));
				free(bin);
			}
			else if (findtype(num1) == 1)
			{
				oct = dectooct(multiplication(octtodec(num1), octtodec(num2)));
				printf("%s \t (%i)\n", oct, multiplication(octtodec(num1), octtodec(num2)));
				free(oct);
			}
			else if(findtype(num1)==2)
			{
				hex = dectohex(multiplication(hextodec(num1), hextodec(num2)));
				printf("%s \t (%i)\n", hex, multiplication(hextodec(num1), hextodec(num2)));
				free(hex);
			}
		}
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*oper == '^')
	{
		if (num1[0]!='-' && num2[0] != '-')
		{

			if (findtype(num1) == 0)
			{
				bin = dectobin(multiplication(bintodec(num1), bintodec(num2)));
				printf("%s \t (%i)\n", bin, multiplication(bintodec(num1), bintodec(num2)));
				free(bin);
			}
			else if (findtype(num1) == 1)
			{
				oct = dectooct(multiplication(octtodec(num1), octtodec(num2)));
				printf("%s \t (%i)\n", oct, multiplication(octtodec(num1), octtodec(num2)));
				free(oct);
			}
			else if(findtype(num1)==2)
			{
				hex = dectohex(multiplication(hextodec(num1), hextodec(num2)));
				printf("%s \t (%i)\n", hex, multiplication(hextodec(num1), hextodec(num2)));
				free(hex);
			}
		}
		else
		{
			printf("ERROR\n");
		}
	}
	else
	{
		printf("ERROR\n");
	}
	free(str);
	free(num1);
	free(num2);
	free(oper);
	exit(0);
}







