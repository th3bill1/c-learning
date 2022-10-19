#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>

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

char str53[40];

char* mystrcat(char* dest, const char* src)
{
	for (int i = 0; i < mystrlen(src); i++)
	{
		str53[i] = src[i];
	}
	for (int i = mystrlen(src); i < (mystrlen(src) + mystrlen(dest)); i++)
	{
		str53[i] = dest[i - mystrlen(src)];
	}
	return str53;
}

const char* mystrchr(const char* src, char c)
{
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == c) return &src[i];
	}
	return NULL;
}

bool ispalindrome(char* src)
{
	for (int i = 0; i < ((mystrlen(src)/2)+1); i++)
	{
		if (src[i] != src[mystrlen(src) - i - 1]) return false;
	}
	return true;
}

void strrmidx(char* src, int n) 
{
	for (int i = n - 1; i < mystrlen(src) + 1; i++)
	{
		src[i] = src[i + 1];
	}
}

void strrmchr(char* src, char ch)
{
	int j = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == ch) 
		{
			j = i;
			break;
		}
	}
	strrmidx(src, j+1);
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
	case 5:
		char str51[] = "I'm blue da ";
		char str52[] = "ba dee da ba da";
		printf("\nString 1: %s", str51);
		printf("\nString 2: %s", str52);
		printf("\nString 1+2: %s", mystrcat(str52, str51));
		break;
	case 6:
		char x6;
		char str61[] = "I'm blue da ba dee";
		printf("Put character you want to search for: ");
		if (scanf(" %c", &x6) == 1)
		{
			printf("First occurence of character %c is: %p", *mystrchr(str61, x6), (void *)mystrchr(str61, x6));
		}
		break;
	case 7:
		char str71[] = "I'm blue eulb m'I";
		char str72[] = "I'm blue de eulb m'I";
		if (ispalindrome(str71) == true) printf("\n%s is a palindrome", &str71);
		else printf("\n%s is a not palindrome", &str71);
		if (ispalindrome(str72) == true) printf("\n%s is a palindrome", &str72);
		else printf("\n%s is not a palindrome", &str72);
		break;
	case 8:
		int x8;
		char str81[] = "I'm blue da ba dee";
		printf("%s\nPut which to remove:", &str81);
		if (scanf("%d", &x8) == 1)
		{
			strrmidx(str81, x8);
			printf("\n%s", str81);
		}
		break;
	case 9:
		char x9;
		char str91[] = "I'm blue da ba dee";
		printf("\n%s", str91);
		printf("\nPut which character you want to remove: ");
		if (scanf(" %c", &x9) == 1)
		{
			strrmchr(str91, x9);
			printf("\n%s", str91);
		}
		break;
	case 10:
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}