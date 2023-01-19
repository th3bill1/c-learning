#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>
#include <string.h>

typedef struct
{
	char first_name[10];
	char last_name[20];
	int semester;
}Student;

int write_lines(char*);
void read_from_file(char*);
void write_students_to_file(char*, Student*, int);
Student* read_students_from_file(char*);
int how_many_elements(char*);
//void characters_to_underscore(char*);

void Set8(int chosenTask)
{
	switch (chosenTask)
	{
		case 1:
			int x = write_lines("set8_task1.txt");
			printf("Number of lines written: %d", x);
			break;
		case 2:
			read_from_file("set8_task1.txt");
			break;
		case 3:
			Student first = { "Benoit","Blanc",1 };
			Student second = { "Miles","Bron",2 };
			Student third = { "Cassandra", "Brand", 3 };
			Student fourth = { "Claire", "Debella", 5 };
			Student students[4] = { first,second,third, fourth };
			write_students_to_file("set8_task3_students.txt", students, 4);
			break;
		case 4:
			Student* students2 = read_students_from_file("set8_task3_students.txt");
			for (int i = 0; i < how_many_elements("set8_task3_students.txt"); i++)
			{
				printf("\n%s %s %d", students2[i].first_name, students2[i].last_name, students2[i].semester);
			}
			break;
		case 6:
			//characters_to_underscore("set8_task1.txt");
			break;
	}
}

int write_lines(char* str)
{
	FILE* f = fopen(str, "a");
	char text[60] = " ";
	int n = 0;
	while (fgets(text, sizeof(text), stdin))
	{
		if (text[0] == '\n') break;
		fprintf(f, text);
		n++;
	}
	fclose(f);
	return n;
}

void read_from_file(char* str)
{
	FILE* f = fopen(str, "r");
	char c[2];
	while (fgets(c, 2, f))
	{
		if ((int)c[0] != 32 && !((int)c[0] > 47 && (int)c[0] < 58) && !((int)c[0] > 64 && (int)c[0] < 91) && !((int)c[0] > 96 && (int)c[0] < 123)) c[0] = '_';
		printf("%s", c);
	}
	fclose(f);
}

void write_students_to_file(char* str, Student* students, int size)
{
	FILE* f = fopen(str, "w");
	fprintf(f, "Size of array: %d", size);
	for (int i = 0; i < size; i++)
	{
		fprintf(f, "\n%s %s %d", students[i].first_name, students[i].last_name, students[i].semester);
	}
	fclose(f);
}

Student* read_students_from_file(char* str)
{
	FILE* f = fopen(str, "r");
	char string[30];
	fgets(string, 30, f);
	int size = atoi(&string[14]);
	char first[100];
	char last[20];
	int sem;
	Student* students = (Student*)calloc(size, sizeof(Student));
	for (int i = 0; i < size; i++)
	{
		fscanf(f, "\n%s %s %d", first, last, &sem);
		strcpy(students[i].first_name, first);
		strcpy(students[i].last_name, last);
		students[i].semester = sem;
	}
	fclose(f);
	return students;
}

int how_many_elements(char* str)
{
	FILE* f = fopen(str, "r");
	char string[30];
	fgets(string, 30, f);
	int size = atoi(&string[14]);
	fclose(f);
	return size;
}

//void characters_to_underscore(char* str)
//{
//	FILE* f = fopen(str, "r+");
//	int c, n=0;
//	while (((c = fgetc(f)) != EOF)&& n<40)
//	{
//		if (c==97)
//		{
//			fseek(f, -1, SEEK_CUR);
//			fputc('_', f);
//		}
//		n++;
//	}
//	fclose(f);
//}