#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TITLE_LEN 31
#define NAME_LEN 21
#define BUFF_SIZE 60
typedef struct Movie
{
	char title[TITLE_LEN];
	char director[NAME_LEN];
	short year;
} Movie;

int write_movies(Movie movies[], int n, const char* filename);
int print_file(const char* filename);

int parse_movie(char* str, Movie* m);
int count_movies(const char* filename);

Movie* read_movies(int count, const char* filename);

int overwrite_movie(const Movie* movie, const char* filename);

#define MV_COUNT 5
int Lab14(void)
{
	
	puts("**********************Part 1**********************");
	const char *movies_file = "movies.txt";
	Movie movies[MV_COUNT] = {
		{ "The Shawshank Redemption", "Frank Darabont", 1994 },
		{ "The Godfather", "Francis Coppola", 1972 },
		{ "The Dark Knight", "Christopher Nolan", 2008 },
		{ "12 Angry Men", "Sidney Lumet", 1957 },
		{ "Schindler's List", "Steven Spielberg", 1993 }
	};
	if (!write_movies(movies, MV_COUNT, movies_file))
		return EXIT_FAILURE;
	if (!print_file(movies_file))
		return EXIT_FAILURE;
	

	
	puts("\n**********************Part 2**********************");
	char movie_str[MV_COUNT][BUFF_SIZE] = {
	//	 ------------------------------|--------------------|-----
		"The Godfather                 |Francis Ford Coppola| 1972\n",
		"The Godfather II              |Francis Ford Coppola| 1974\n",
		"Pulp Fiction                  |Quentin Tarantino     1994\n",
		"The Good, the Bad and the Ugly Sergio Leone        | 1966\n",
		"Fight Club |David Fincher       | 1999\n",
	};
	memset(movies, 0, sizeof(Movie)*MV_COUNT);
	int i;
	for (i = 0; i < MV_COUNT; ++i)
	{
		int r = parse_movie(movie_str[i], movies + i);
		if (!r)
		{
			if (movies[i].year != 0)
			{
				puts("If parsing failed, movie year should be 0!");
				return EXIT_FAILURE;
			}
			puts("Invalid format");
		}
		else
			printf("[%s] [%s] %hd\n", movies[i].title, movies[i].director, movies[i].year);
	}
	int count = count_movies(movies_file);
	printf("Movie count: %d\n", count);

	
	puts("\n**********************Part 3**********************");
	printf("Requesting %d movies:\n", 3);
	Movie *selected = read_movies(3, movies_file);
	if (!selected)
		return EXIT_FAILURE;
	for (i = 0; i < 3; ++i)
		printf("[%s] [%s] %hd\n", selected[i].title, selected[i].director, selected[i].year);
	free(selected);
	printf("Requesting %d movies:\n", count + 1);
	selected = read_movies(count + 1, movies_file);
	if (selected)
	{
		puts("Requested movie doesn't exist, returned value should be NULL!");
		free(selected);
	}
	else
		puts("At least one movie doesn't exist");
	

	/*
	puts("\n**********************Part 4**********************");
	if (!overwrite_movie(movies, movies_file))
		return EXIT_FAILURE;
	if (!overwrite_movie(movies + 1, movies_file))
		return EXIT_FAILURE;
	if (!print_file(movies_file))
		return EXIT_FAILURE;
	*/
	return EXIT_SUCCESS;
}

int write_movies(Movie movies[], int n, const char* filename)
{
	FILE* f = fopen(filename, "w");
	fprintf(f,"             Title             |       Director       | Year\n-------------------------------|----------------------|-----\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%-30s | %-20s | %d\n", movies[i].title, movies[i].director, movies[i].year);
	}
	fclose(f);
	return 1;
}

int print_file(const char* filename)
{
	FILE* f = fopen(filename, "r");
	char c;
	while ((c=(char)fgetc(f)) != EOF)
	{
		printf("%c", c);
	}
	fclose(f);
	return 1;
}

int parse_movie(char* str, Movie* m)
{
	if (sscanf(str, "%30[^|\n] |%20[^|\n] |%hd", &m->title, &m->director, &m->year)==3)
	{
		//if (isspace(m->title[strlen(m->title) - 1])) printf("1");
		for (int i = (int)strlen(m->title)-1; i > 0; i--)
		{
			if (!isspace(m->title[i])) break;
			if (isspace(m->title[i]))
			{
				m->title[i] = '\0';
			}
			
		}
		for (int i = (int)strlen(m->director)-1; i > 0; i--)
		{
			if (!isspace(m->director[i])) break;
			if (isspace(m->director[i]))
			{
				m->director[i] = '\0';
			}
		}
		return 1;
	}
	return 0;
}

int count_movies(const char* filename)
{
	FILE* f = fopen(filename, "r");
	char buffer[100];
	fgets(buffer, 100, f);
	fgets(buffer, 100, f);
	char buffer1[100];
	int n = 0;
	while (fgets(buffer1,100,f) != NULL) n++;
	fclose(f);
	return n;
}

Movie* read_movies(int count, const char* filename)
{
	if (count_movies(filename) > count)
	{
		Movie* movies = (Movie*)calloc(count, sizeof(Movie));
		FILE* f = fopen(filename, "r");
		char buffer[100];
		fgets(buffer, 100, f);
		fgets(buffer, 100, f);
		for (int i = 0; i < count; i++)
		{
			fgets(buffer, 100, f);
			parse_movie(buffer, &movies[i]);
		}
		fclose(f);
		return movies;
	}
	return NULL;
}