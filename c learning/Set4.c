#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>

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

void strrmchrevery(char* src, char ch)
{
	int j = 0, i = 0;
	while( i < mystrlen(src))
	{
		if (src[i] == ch)
		{
			j = i;
			strrmidx(src, j + 1);
			i--;
		}
		i++;
	}
}

void strrmchrupper(char* src)
{
	int j = 0, i = 0;
	while (i < mystrlen(src))
	{
		if ((int)src[i]>64 && (int)src[i] < 91)
		{
			j = i;
			strrmidx(src, j + 1);
			i--;
		}
		i++;
	}
}

void srtrmsub(char* src, int start, int length)
{
	int j = start - 1;
	for (int i = 0; i < length; i++)
	{
		strrmidx(src, j);
	}
}

void strrmstr(char* src, char* toremove)
{
	int k = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == toremove[0])
		{
			for (int j = 0; j < mystrlen(toremove); j++)
			{
				if (src[i + j] != toremove[j]) break;
				k=j;
			}
			if (k == mystrlen(toremove)-1) srtrmsub(src, i+2, mystrlen(toremove));
			k = 0;
		}
	}
}

int strrplcch(char* src, char toreplace, char replacewith)
{
	int k = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == toreplace)
		{
			src[i] = replacewith;
			k++;
		}

	}
	return k;
}

void strlower_to_upper(char* src)
{
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] > 96 && src[i] < 123) src[i] -= 32;
	}
}

void strrplcsub(char* src, int start, int length, const char* replacement)
{
	for (int i = 0; i < length && i<mystrlen(replacement);i++)
	{
		src[start + i-1] = replacement[i];
	}
}

int strrplcstr(char* src, const char* toreplace, const char* replacewith)
{
	int k = 0, l = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == toreplace[0])
		{
			for (int j = 0; j < mystrlen(toreplace); j++)
			{
				if (src[i + j] != toreplace[j]) break;
				k = j;
			}
			if (k == mystrlen(toreplace) - 1)
			{
				strrplcsub(src, i+1, k, replacewith);
				if (mystrlen(replacewith) < mystrlen(toreplace))
				{
					srtrmsub(src, i + 2 + k, mystrlen(toreplace) - mystrlen(replacewith));
					printf("\n1");
				}
				l++;
			}
			k = 0;
		}
	}
	return l;
}

void move_string(char* src, int start, int length)
{
	char str[200];
	for (int i = 0; i < start; i++)
	{
		str[i] = src[i];
	}
	for (int j = start; j < start + length; j++)
	{
		str[j] = ' ';
	}
	for (int k = start + length; k < mystrlen(src); k++)
	{
		str[k] = src[k - length];
	}
	for (int l = 0; l < mystrlen(src); l++)
	{
		src[l] = str[l];
	}
}

void strrplcstr_with_moving(char* src, const char* toreplace, const char* replacewith)
{
	int k = 0;
	for (int i = 0; i < mystrlen(src); i++)
	{
		if (src[i] == toreplace[0])
		{
			for (int j = 0; j < mystrlen(toreplace); j++)
			{
				if (src[i + j] != toreplace[j]) break;
				k = j;
			}
			if (k == mystrlen(toreplace) - 1)
			{
				move_string(src, i + 1, mystrlen(replacewith)-mystrlen(toreplace));
				strrplcsub(src, i + 1, k+mystrlen(replacewith), replacewith);
			}
			k = 0;
		}
	}
}

void numbers_to_words(char* src)
{
	strrplcstr_with_moving(src, " 1 ", " one ");
	strrplcstr_with_moving(src, " 2 ", " two ");
	strrplcstr_with_moving(src, " 3 ", " three ");
	strrplcstr_with_moving(src, " 4 ", " four ");
	strrplcstr_with_moving(src, " 5 ", " five ");
	strrplcstr_with_moving(src, " 6 ", " six ");
	strrplcstr_with_moving(src, " 7 ", " seven ");
	strrplcstr_with_moving(src, " 8 ", " eight ");
	strrplcstr_with_moving(src, " 9 ", " nine ");
	strrplcstr_with_moving(src, " 10 ", " ten ");
	strrplcstr_with_moving(src, " 11 ", " eleven ");
	strrplcstr_with_moving(src, " 12 ", " twelve ");
}

int find_pos_min(double y[], int startpos, int length)
{
	int k = 0;
	double min = DBL_MAX;
	for (int i = startpos; i < length; i++)
	{
		if (y[i] < min)
		{
			min = y[i];
			k = i;
		}
	}
	return k;
}

void selection_sort(double x[], int length)
{
	double temp;
	for (int i = 0; i < length; i++)
	{
		int k = find_pos_min(x, i, length);
		temp = x[i];
		x[i] = x[k];
		x[k] = temp;
	}
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
		char x10;
		char str101[] = "I'm blue da ba dee";
		printf("\n%s", str101);
		printf("\nPut which character you want to remove: ");
		if (scanf(" %c", &x10) == 1)
		{
			strrmchrevery(str101, x10);
			printf("\n%s", str101);
		}
		break;
	case 11:
		char str111[] = "I'm BlUe dA ba deE";
		printf("\nBefore removing uppercase letters: %s", str111);
		strrmchrupper(str111);
		printf("\nAfter removing uppercase letters:%s", str111);
		break;
	case 12:
		int x12, y12;
		char str121[] = "I'm blue da ba dee";
		printf("\n%s", str121);
		printf("\nPut first character you want to remove and length: ");
		if (scanf(" %d %d", &x12, &y12) == 2)
		{
			srtrmsub(str121, x12, y12);
			printf("\n%s", str121);
		}
		break;
	case 13:
		char str131[] = "I'm blue da ba dee blue da ba blue";
		char str132[20];
		printf("\n%s", str131);
		printf("\nPut string you want to remove: ");
		if (scanf(" %s", &str132) == 1)
		{
			strrmstr(str131, str132);
			printf("\n%s", str131);
		}
		break;
	case 14:
		char str141[] = "I'm blue da ba dee";
		char x14, y14;
		printf("\n%s", str141);
		printf("\nPut character you want to replace and character you want put instead: ");
		if (scanf(" %c %c", &x14, &y14) == 2)
		{
			int n14 = strrplcch(str141, x14, y14);
			printf("\nString: %s\n%d character(s) replaced", str141, n14);
		}
		break;
	case 15:
		char str151[] = "I'm blue da ba dee";
		printf("\nBefore change: %s", str151);
		strlower_to_upper(str151);
		printf("\nAfter change: %s", str151);
		break;
	case 16:
		int x16, y16;
		char str161[] = "I'm blue da ba dee";
		char str162[30];
		printf("\n%s", str161);
		printf("\nPut a substring, starting position and length: ");
		if (scanf(" %s %d %d", &str162,&x16, &y16) == 3)
		{
			strrplcsub(str161, x16, y16, str162);
			printf("String after replacement: %s", str161);
		}
		break;
	case 17:
		char str171[] = "I'm blue da ba dee blue da ba blue";
		char str172[20], str173[20];
		printf("\nBefore changes: %s", str171);
		printf("\nPut a substring you want to replace and its replacement: ");
		if (scanf(" %s %s", &str172, &str173) == 2)
		{
			int n17 = strrplcstr(str171, str172, str173);
			printf("String after %d replacements: %s", n17, str171);
		}
		break;
	case 18:
		char str181[200] = "44 3 143 12 5 8 11 7 156                          "; //need to figure it out how to skip this part
		printf("\nBefore changes: %s", str181);
		numbers_to_words(str181);
		printf("\nAfter replacements: %s", str181);
		break;
	case 19:
		int length = 6;
		double x19[] = { 12, 1.5, 21.5, 23.7, 17.345, 15.5 };
		double y19[] = { 12, 1.5, 21.5, 23.7, 17.345, 15.5 };
		double z19[] = { 12, 1.5, 21.5, 23.7, 17.345, 15.5 };
		printf("\nBefore sorting: ");
		for (int i = 0; i < length; i++)
		{
			printf("%lf ", x19[i]);
		}
		selection_sort(x19, length);
		printf("\nAfter sorting: ");
		for (int i = 0; i < length; i++)
		{
			printf("%lf ", x19[i]);
		}
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}