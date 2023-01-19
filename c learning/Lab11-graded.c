#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

typedef struct _pixel
{
	char sign;
	int color;
}pixel;

typedef struct _card
{
	int rows;
	int columns;
	pixel* arr;
}card;

typedef struct _christmas_card
{
	int width;
	int height;
	int num_of_gems;
	card picture;
}christmas_card;

int coordinates2index(int r, int c, int columns);
void set_pixel(pixel* s, char n_sign, int n_color);
void init_card(card* ca, int n_rows, int n_columns, pixel init_pixel);
void free_card(card* ca);
void print_card(card* ca);

void create_christmas_card_a(christmas_card* cc, int width, int height, int num_of_gems, pixel* colorful_pixels);
void create_christmas_card_b(christmas_card* cc, int height, int num_of_gems, pixel* colorful_pixels);
void print_christmas_card(christmas_card* cc);
void free_christmas_card(christmas_card* ct);
void paint_christmas_card(christmas_card* cc, pixel* colorful_pixels);

void version_a11();
void version_b11();

void Lab11(void)
{
	int choice;
	printf("\nChoose version ( A - 1  B - 2 ): ");
	if (scanf("%d", &choice) == 1)
	{
		switch (choice)
		{
		case 1:
			version_a11();
			break;
		case 2:
			version_b11();
			break;
		default:
			break;
		}
	}
}

void version_a11()
{
	printf(" ********************* Part 1 ********************* \n");
	
		pixel  colorful_pixels[4];
		printf("Converting indexes, setting and printing color pixels\n\n");
		printf("For 3x3 matrix, 2d index [1][1] after conversion gives 1d index [%d]\n\n", coordinates2index(1, 1, 3));
		set_pixel(&colorful_pixels[0], '*', 2); // green_star
		set_pixel(&colorful_pixels[1], '|', 15); // white_line
		set_pixel(&colorful_pixels[2], '@', 14); // yellow_ornament
		set_pixel(&colorful_pixels[3], ' ', 15); // white space

		HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[0].color);
		printf("%c", colorful_pixels[0].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[1].color);
		printf("%c", colorful_pixels[1].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[2].color);
		printf("%c", colorful_pixels[2].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[3].color);
		printf("%c", colorful_pixels[3].sign);
		printf("\n\n");
	
	printf(" ********************* Part 2 ********************* \n");
	
		printf("Initializing and printing card\n\n");
		card card;
		init_card(&card, 15, 10, colorful_pixels[0]);
		print_card(&card);
		free_card(&card);
		printf("\n\n");
	
	printf(" ********************* Part 3 ********************* \n");
	
		christmas_card cc2, cc3;
		printf("Creating and printing tree\n\n");
		create_christmas_card_a(&cc3, 7, 3, 10, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
		create_christmas_card_a(&cc2, 5, 2, 5, colorful_pixels);
		print_christmas_card(&cc2);
		printf("\n\n");
	
	printf(" ********************* Part 4 ********************* \n");
	
		printf("Decorating and printing tree\n\n");
		paint_christmas_card(&cc3, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
		paint_christmas_card(&cc2, colorful_pixels);
		print_christmas_card(&cc2);
		printf("\n\n");
	

		free_christmas_card(&cc3);
		free_christmas_card(&cc2);
		printf("\n\n");
}

void version_b11()
{
	printf(" ********************* Part 1 ********************* \n");
	
		pixel  colorful_pixels[4];
		printf("Converting indexes, setting and printing color pixels\n\n");
		printf("For 3x3 matrix, 2d index [1][1] after conversion gives 1d index [%d]\n\n", coordinates2index(1, 1, 3));
		set_pixel(&colorful_pixels[0], '*', 2); // green_star
		set_pixel(&colorful_pixels[1], '|', 15); // white_line
		set_pixel(&colorful_pixels[2], 'i', 4); // red_candle
		set_pixel(&colorful_pixels[3], ' ', 15); // white space

		HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[0].color);
		printf("%c", colorful_pixels[0].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[1].color);
		printf("%c", colorful_pixels[1].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[2].color);
		printf("%c", colorful_pixels[2].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[3].color);
		printf("%c", colorful_pixels[3].sign);
		printf("\n\n");
	
	printf(" ********************* Part 2 ********************* \n");
	
		card card;
		printf("Initializing and printing card\n\n");
		init_card(&card, 15, 10, colorful_pixels[0]);
		print_card(&card);
		free_card(&card);
		printf("\n\n");
	
	printf(" ********************* Part 3 ********************* \n");
	
		christmas_card cc5, cc3;
		printf("Creating and printing tree\n\n");
		create_christmas_card_b(&cc5, 5, 10, colorful_pixels);
		print_christmas_card(&cc5);
		printf("\n\n");
		create_christmas_card_b(&cc3, 3, 5, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
	
	printf(" ********************* Part 4 ********************* \n");
	
		printf("Decorating and printing tree\n\n");
		paint_christmas_card(&cc5, colorful_pixels);
		print_christmas_card(&cc5);
		printf("\n\n");
		paint_christmas_card(&cc3, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
	
	// uncomment with part 3 and 4

	free_christmas_card(&cc5);
	free_christmas_card(&cc3);
	printf("\n\n");

}

int coordinates2index(int r, int c, int columns)
{
	return r * columns + c;
}

void print_card(card* ca)
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < ca->rows; i++)
	{
		for (int j = 0; j < ca->columns; j++)
		{
			SetConsoleTextAttribute(hconsole, (WORD)ca->arr[coordinates2index(i, j, ca->columns)].color);
			printf("%c", ca->arr[coordinates2index(i,j,ca->columns)].sign);
		}
		printf("\n");
	}

	SetConsoleTextAttribute(hconsole, 15);
}

void set_pixel(pixel* s, char n_sign, int n_color)
{
	s->color = n_color;
	s->sign = n_sign;
}

void init_card(card* ca, int n_rows, int n_columns, pixel init_pixel)
{
	pixel* new_pixel = (pixel*)calloc(n_rows * n_columns, sizeof(pixel));
	for (int i = 0; i < n_rows * n_columns; i++)
	{
		new_pixel[i].color = init_pixel.color;
		new_pixel[i].sign = init_pixel.sign;
	}
	ca->arr = new_pixel;
	ca->columns = n_columns;
	ca->rows = n_rows;
}

void free_card(card* ca)
{
	free(ca->arr);
	ca->columns = 0;
	ca->rows = 0;
}

void create_christmas_card_a(christmas_card* cc, int width, int height, int num_of_gems, pixel* colorful_pixels)
{
	cc->height = height;
	cc->num_of_gems = num_of_gems;
	cc->width = width;
	card new_card;
	int picture_height = width * height;
	int picture_width = (width + 2 * (height - 1))*2-1;
	init_card(&new_card, picture_height, picture_width, colorful_pixels[3]);
	int k = 0;
	int l = picture_width;
	int m = 0;
	for (int i = picture_height-1; i >= 0; i--)
	{
		m = 0;
		for (int j = l-1; j >= k; j--)
		{
			if (m == 0)
			{
				set_pixel(&new_card.arr[coordinates2index(i, j, picture_width)], colorful_pixels[0].sign, colorful_pixels[0].color);
				m++;
			}
			else m = 0;
		}
		l--;
		k++;
		if (i % width == 0)
		{
			l += 2*height-1;
			k -= 2*height-1;
		}
	}
	cc->picture = new_card;
}

void print_christmas_card(christmas_card* cc)
{
	print_card(&cc->picture);
}

void free_christmas_card(christmas_card* cc)
{
	free_card(&cc->picture);
	cc->height = 0;
	cc->num_of_gems = 0;
	cc->width = 0;
}

void paint_christmas_card(christmas_card* cc, pixel* colorful_pixels)
{
	srand((unsigned int)time(NULL));
	int i = 0, y;
	while (i < cc->num_of_gems)
	{
		y = (rand() % (cc->picture.columns * cc->picture.rows));
		if (y > (cc->picture.columns*cc->picture.rows)) y -= cc->height * cc->width;
		if (cc->picture.arr[y].sign == colorful_pixels[0].sign)
		{
			set_pixel(&cc->picture.arr[y], colorful_pixels[2].sign, colorful_pixels[2].color);
			i++;
		}
	}
}

void create_christmas_card_b(christmas_card* cc, int height, int num_of_gems, pixel* colorful_pixels)
{
	cc->height = height;
	cc->num_of_gems = num_of_gems;
	card new_card;
	int picture_height = height*3+1;
	int picture_width = ((height-1)*2+5)*2-1;
	init_card(&new_card, picture_height, picture_width, colorful_pixels[3]);
	int k = 0;
	int l = picture_width;
	int m = 0;
	for (int i = picture_height - 2; i >= 0; i--)
	{
		m = 0;
		for (int j = l - 1; j >= k; j--)
		{
			if (m == 0)
			{
				set_pixel(&new_card.arr[coordinates2index(i, j, picture_width)], colorful_pixels[0].sign, colorful_pixels[0].color);
				m++;
			}
			else m = 0;
		}
		l -= 2;
		k += 2;
		if (i % 3 == 0)
		{
			l += 4;
			k -= 4;
		}
	}
	set_pixel(&new_card.arr[coordinates2index(picture_height-1, (picture_width+1)/2-1, picture_width)], colorful_pixels[1].sign, colorful_pixels[1].color);
	cc->picture = new_card;
}