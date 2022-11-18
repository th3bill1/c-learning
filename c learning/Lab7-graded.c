#include <stdio.h>

int is_lowercase(char);
int is_uppercase(char);
void replace_letters(char[], const char[]);
void split_lines(char[], int);
void count_letters(char[], int[]);
void print_letter_stats(int[]);
void Lab7(void)
{
	/********************************* Part 1 *********************************/

	puts("******** Part 1 ********");

	const char* chars = "A;b0Cf9";
	printf("Char.\tLower.\tUpper.\n");
	int i;
	for (i = 0; i < 7; ++i)
		printf("%c\t%d\t%d\n", chars[i], is_lowercase(chars[i]), is_uppercase(chars[i]));

	/********************************* Part 2 *********************************/

	puts("******** Part 2 ********");

	char message[300] =
		"A good glass in the bishop's hostel in the devil's seat\n"
		"forty - one degrees and thirteen minutes northeast and by north\n"
		"main branch seventh limb east side\n"
		"shoot from the left eye of the death's-head\n"
		"a bee line from the tree through the shot fifty feet out.";
	const char* zebras = "zebrascdfghijklmnopqtuvwxy";
	replace_letters(message, zebras);
	puts(message);

	/********************************* Part 4 *********************************/

	puts("******** Part 4 ********");

	split_lines(message, 29);
	puts(message);

	/********************************* Part 5 *********************************/

	puts("******** Part 5 ********");

	int counts[26];
	count_letters(message, counts);
	print_letter_stats(counts);
}

int strlen(char* x)
{
	int y = 0;
	while (*x != '\0')
	{
		y++;
		x++;
	}
	return y;
}

int is_lowercase(char t)
{
	if (t >= 'a' && t <= 'z') return 1;
	return 0;
}

int is_uppercase(char t)
{
	if (t >= 'A' && t <= 'Z') return 1;
	return 0;
}

void replace_letters(char* message, const char* code)
{
	for (int i = 0; i < 300; i++)
	{
		if (is_lowercase(message[i])) message[i] = code[message[i] - 97];
		if (is_uppercase(message[i])) message[i] = code[message[i] - 65];

	}
	int i = 0;
	while (*(message + i) != '\0')
	{
		if ((!is_lowercase(message[i]) && (!is_uppercase(message[i]))))
		{
			int j = i;
			while (message[j] != '\0')
			{
				message[j] = message[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	int k = strlen(message);
	while (message[k - 1] == '\n')
	{
		message[k - 1] = '\0';
		k--;
	}
}

void split_lines(char* message, int x)
{
	int temp = 0;
	while (*(message + temp) != '\0')
	{

		if (temp % (x + 1) == 0)
		{

			int a = strlen(message) + 2;
			message[a] = '\0';
			a--;
			while ((message + a) != (message + temp))
			{

				message[a] = message[a - 1];
				a--;
			}
			*(message + temp) = '\n';

		}
		temp++;

	}
}

void count_letters(char* message, int* x)
{
	int i = 0;
	for (int j = 0; j < 26; j++)
	{
		x[j] = 0;
	}
	while (message[i] != '\0')
	{
		if (message[i] - 97 < 26) x[message[i] - 97] += 1;
		i++;
	}
}

void print_letter_stats(int* x)
{
	int a = 'a';
	printf("\nLettter\tCount:");
	for (int i = 0; i < 26; i++)
	{
		printf("\n%c:\t%d", a + i, x[i]);
	}
}