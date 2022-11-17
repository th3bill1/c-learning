#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_LEN 100
#define EXAMPLE_COUNT 3

int is_separator(int c);
int is_letter(int c);
const char* match_separators(const char* src);
const char* match_word(const char* src);
int match_pattern(const char* src, const char* pattern);
void pattern_replace(char src[]);

int Lab6(void)
{
	/***************************************Part 1*************************************************/

	puts("*****Part 1*****");
	printf("[%c] %s an separator\n", '.', is_separator('.') ? "is" : "is not");
	printf("[%c] %s an separator\n", ';', is_separator(';') ? "is" : "is not");
	printf("[%c] %s an separator\n", '\n', is_separator('\n') ? "is" : "is not");
	printf("[%c] %s an separator\n", ' ', is_separator(' ') ? "is" : "is not");
	printf("[%c] %s an separator\n", 'A', is_separator('A') ? "is" : "is not");
	putchar('\n');
	printf("[%c] %s a letter\n", 'Z', is_letter('Z') ? "is" : "is not");
	printf("[%c] %s a letter\n", 'f', is_letter('f') ? "is" : "is not");
	printf("[%c] %s a letter\n", '\t', is_letter('\t') ? "is" : "is not");
	printf("[%c] %s a letter\n", ' ', is_letter(' ') ? "is" : "is not");
	printf("[%c] %s a letter\n", 'g', is_letter('g') ? "is" : "is not");


	/***************************************Part 2*************************************************/

	puts("\n*****Part 2*****");
	char words[] = "Quick brown fox17";
	char* start;
	puts("Words: ");
	for (start = words; *start != '\0';)
	{
		//non-const char* passed, so the result can be safely cast back to non-const char *
		char* end = (char*)match_word(start);
		if (end == start)
			break;
		*end = '\0';
		printf("[%s]\n", start);
		start = end + 1;
	}

	char separators[] = "., ;\t;\n.:%";
	puts("\nSeparators:");
	for (start = separators; *start != '\0';)
	{
		//non-const char* passed, so the result can be safely cast back to non-const char *
		char* end = (char*)match_separators(start);
		if (end == start)
			break;
		*end = '\0';
		printf("[%s]\n", start);
		start = end + 1;
	}


	/***************************************Part 3*************************************************/

	puts("\n*****Part 3*****");
	const char* pattern = "/w/s/w";
	printf("Pattern: [%s]\n", pattern);
	const char* text_p1[EXAMPLE_COUNT] = { "ul. Koszykowa", "Aleje Jerozolimskie 144", "ul. 30-lecia" };
	int i;
	for (i = 0; i < EXAMPLE_COUNT; ++i)
		printf("[%s] %s a match\n", text_p1[i], match_pattern(text_p1[i], pattern) ? "is" : "is not");

	pattern = "#/w/s#/w";
	printf("\nPattern: [%s]\n", pattern);
	const char* text_p2[EXAMPLE_COUNT] = { "#programming \t #rules", "#algebra #drools_", " #p1 #ftw" };
	for (i = 0; i < EXAMPLE_COUNT; ++i)
		printf("[%s] %s a match\n", text_p2[i], match_pattern(text_p2[i], pattern) ? "is" : "is not");


	/***************************************Part 4*************************************************/

	puts("\n*****Part 4*****");
	char pbuffer[BUFF_LEN] = "", tbuffer[BUFF_LEN] = "";
	puts("Input text sample:");
	fgets(pbuffer, BUFF_LEN, stdin);
	printf("[%s]", pbuffer);
	pattern_replace(pbuffer);
	printf("Pattern: [%s]\n", pbuffer);
	for (;;)
	{
		puts("Input next text sample:");
		fgets(tbuffer, BUFF_LEN, stdin);
		if (match_pattern(tbuffer, pbuffer))
			puts("It's a match!");
		else
		{
			puts("It's not a match!");
			break;
		}
	}


	return 0;
}


int is_letter(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
	return 0;
}

int is_separator(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '.' || c == ',') return 1;
	return 0;
}

const char* match_word(const char* src)
{
	while (*src != '\0' && is_letter(*src))
	{
		src++;
	}
	return src;
}

const char* match_separators(const char* src)
{
	while (*src != '\0' && is_separator(*src))
	{
		src++;
	}
	return src;
}

int match_pattern(const char* src, const char* pattern)
{
	while (*src != '\0')
	{
		if (*pattern == '/' && *(pattern + 1) == 'w')
		{
			if (is_letter(*src))
			{
				src = match_word(src);
				pattern += 2;
			}
			else return 0;
		}
		else if (*pattern == '/' && *(pattern + 1) == 's')
		{
			if (is_separator(*src))
			{
				src = match_separators(src);
				pattern += 2;
			}
			else return 0;
		}
		else if (*src == *pattern)
		{
			src++;
			pattern++;
		}
		else return 0;
	}
	return 1;
}

void pattern_replace(char src[])
{
	int temp = 0;
	while (*(src + temp + 1) != '\0' && *(src+temp) != '\0')
	{
		if (is_letter(*(src+temp)) && is_letter(*(src + temp + 1)))
		{
			__int64 j = match_word(src+temp)-src-temp-2;
			int i = 2;
			while (*(src + temp + i + j-1) != '\0')
			{
				*(src + temp + i) = *(src + temp + i + j);
				i++;
			}
			*(src + temp) = '/';
			*(src + temp + 1) = 'w';
			temp += 2;
		}
		if (is_separator(*(src+temp)) && is_separator(*(src + temp + 1)))
		{
			__int64 j = match_separators(src + temp) - src - temp - 2;
			int i = 2;
			while (*(src + temp + i + j-1) != '\0')
			{
				*(src + temp + i) = *(src + temp + i + j);
				i++;
			}
			*(src + temp) = '/';
			*(src + temp + 1) = 's';
			temp += 2;
		}
		else temp++;
	}
}