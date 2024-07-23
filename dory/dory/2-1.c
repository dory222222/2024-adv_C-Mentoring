#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning (disable : 6031)

int main(void)
{
	int n,i ,j, len = 0;
	int a100, a10, a1;
	int b100, b10, b1;
	char st1[13] = { 0 };
	char st2[5] = { 0 };
	char st3[5] = { 0 };
	scanf("%d", &n);

	a100 = n / 100;				//100의 자리수
	a10 = n / 10 - a100 * 10;  //10의 자리수
	a1 = n % 10;				//1의 자리수

	b100 = a100 / 5;
	b10 = a10 / 5;
	b1 = a1 / 5;
	//////////////////// 100의 자리수 ///////////////////////
	if (b100 == 1)
	{
		for (i = 1; i < 4; i++)
		{
			if (a100 % 9 == 0)
			{
				st1[0] = 'C';
				st1[1] = 'M';
				break;
			}
			else if (a100 % 5 == i)
			{
				st1[0] = 'D';
				j = 1;
				while (j <= i)
				{
					st1[j] = 'C';
					j++;
				}
				break;
			}
		}
	}
	else
	{
		for (i = 1; i < 4; i++)
		{
			if (a100 == 0) break;
			if (a100 % 4 == 0)
			{
				st1[0] = 'C';
				st1[1] = 'D';
				break;
			}
			else if (a100 % 5 == i)
			{
				j = 0;
				while (j <= i - 1)
				{
					st1[j] = 'C';
					j++;
				}
				break;
			}
		}
	}
	/////////////////// 10의 자리수 ////////////////
	if (b10 == 1)
	{
		for (i = 1; i < 4; i++)
		{
			if (a10 % 9 == 0)
			{
				st2[0] = 'X';
				st2[1] = 'C';
				break;
			}
			else if (a10 % 5 == i)
			{
				st2[0] = 'L';
				j = 1;
				while (j <= i)
				{
					st2[j] = 'X';
					j++;
				}
				break;
			}
		}
	}
	else
	{
		for (i = 1; i < 4; i++)
		{
			if (a10 == 0) break;
			if (a10 % 4 == 0)
			{
				st2[0] = 'X';
				st2[1] = 'L';
				break;
			}
			else if (a10 % 5 == i)
			{
				j = 0;
				while (j <= i - 1)
				{
					st2[j] = 'X';
					j++;
				}
				break;
			}
		}
	}
	////////////////// 1의 자리수 ////////////////////////
	if (b1 == 1)
	{
		for (i = 1; i < 4; i++)
		{
			if (a1 % 9 == 0)
			{
				st3[0] = 'I';
				st3[1] = 'X';
				break;
			}
			else if (a1 % 5 == i)
			{
				st3[0] = 'V';
				j = 1;
				while (j <= i)
				{
					st3[j] = 'I';
					j++;
				}
				break;
			}
		}
	}
	else
	{
		for (i = 1; i < 4; i++)
		{
			if (a1 == 0) break;
			if (a1 % 4 == 0)
			{
				st3[0] = 'I';
				st3[1] = 'V';
				break;
			}
			else if (a1 % 5 == i)
			{
				j = 0;
				while (j <= i - 1)
				{
					st3[j] = 'I';
					j++;
				}
				break;
			}
		}
	}
	strcat(st1, st2);
	strcat(st1, st3);
		printf("%d = %d + %d + %d = %s ,%d", n, a100 * 100, a10 * 10, a1,st1,(int)strlen(st1));

	return 0;
}