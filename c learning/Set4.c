#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int mystrlen(const char* src)
{
	int i = 0;
	while(1)
	{
		if (src[i] == '\0') return i;
		i++;
	}
}

void mystrcpy(char* dest, const char* src)
{
	int j = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		dest[i] = src[i];
		j = i;
	}
	dest[j+1] = '\0';
}

int mystrcmp(char* dest, const char* src)
{
	if (mystrlen(src) != mystrlen(dest)) return -1;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if(dest[i] != src[i]) return -1;
	}
	return 0;
}

int mystrncmp(char* dest, const char* src, int n) //it's less messy with int than with size_t
{
	int k;
	if (mystrlen(dest) < n && mystrlen(dest)==mystrlen(src)) k = mystrlen(dest);
	else k = n;
	for (int i = 0; i < k; i++)
	{
		if (dest[i] != src[i]) return -1;
	}
	return 0;
}

void Set4(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		char str1[] = "I'm blue da ba dee";
		printf("Length of this string is equal to %d.", mystrlen(str1));
		break;
	case 2:
		char str21[] = "I'm blue da ba dee";
		char str22[50];
		mystrcpy(str22, str21);
		printf("%s", str22);
		break;
	case 3:
		char str31[] = "I'm blue da ba dee";
		char str32[] = "I'm blue da ba dee";
		char str33[] = "I'm blue da ba deee";
		if (mystrcmp(str31, str32) == 0) printf("\nFirst two strings are equal");
		else printf("\nFirst two strings are not equal");
		if (mystrcmp(str31, str33) == 0) printf("\nFirst and third string are equal");
		else printf("\nFirst and third string are not equal");
		break;
	case 4:
		int x4;
		char str41[] = "I'm blue da ba dee";
		char str42[] = "I'm blue da ba deea";
		printf("Put how many first elements to compare: ");
		if (scanf("%d", &x4) == 1)
		{
			if (mystrncmp(str41, str42, x4) == 0) printf("First %d elements of this 2 strings are equal", x4);
			else printf("First %d elements of this 2 strings are not equal", x4);
		}
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}