#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial
{
	int deg;
	int* coeff;
}Poly;

void initialize_poly(Poly* p);
void print_poly(Poly* p);
void fill_poly(Poly* p, int deg, int* coeff);
void fill_poly_rand(Poly* p, int deg);
void clean_poly(Poly* p);
void extend_poly(Poly* p, int new_deg);
int evaluate_poly(Poly* p, int x);
void sum_polly(Poly* p1, Poly* p2, Poly* p3);


void Lab10()
{

	Poly p1, p2, p3;

	printf("\n************** Task 1 (1 points) **************\n");
	initialize_poly(&p1);
	initialize_poly(&p2);
	initialize_poly(&p3);
	printf("p1: "); print_poly(&p1);printf("\n");

	printf("\n************** Task 2 (2 points) **************\n");
	int coeff[] = { 1, -2, 3, -4, 5, -6 };
	fill_poly(&p1, 5, coeff);
	fill_poly_rand(&p2, 2);
	printf("p1: "); print_poly(&p1);
	printf("\np2: "); print_poly(&p2);printf("\n");

	printf("\n************** Task 3 (1 points) **************\n");
	extend_poly(&p2, 4);
	printf("p2: "); print_poly(&p2);printf("\n");

	printf("\n************** Task 4 (2 points) **************\n");
	printf("p1(1): "); printf("%d\n", evaluate_poly(&p1, 1));printf("\n");

	printf("\n************** Task 5 (2 points) **************\n");
	sum_polly(&p1, &p2, &p3);
	printf("p1: "); print_poly(&p1);
	printf("\np2: "); print_poly(&p2);
	printf("\np1+p2: "); print_poly(&p3);
	sum_polly(&p2, &p1, &p3);
	printf("\np2+p1: "); print_poly(&p3);
	clean_poly(&p1);
	clean_poly(&p2);
	clean_poly(&p3);
}

void initialize_poly(Poly* p)
{
	p->coeff = NULL;
	p->deg = -1;
}

void print_poly(Poly* p)
{
	if (p->deg == -1) printf("Empty polynomial");
	else
	{
		printf("%dx^%d", p->coeff[p->deg], p->deg);
		for (int i = p->deg - 1; i > 1; i--)
		{
			if (p->coeff[i] >= 0) printf("+");
			printf("%dx^%d", p->coeff[i], i);
		}
		if (p->coeff[1] >= 0) printf("+");
		printf("%dx", p->coeff[1]);
		if (p->coeff[0] >= 0) printf("+");
		printf("%d", p->coeff[0]);
	}
}

void fill_poly(Poly* p, int deg, int* coeff)
{
	p->deg = deg;
	p->coeff = (int*)calloc(deg + 1, sizeof(int));
	for (int i = 0; i <= deg; i++)
	{
		p->coeff[i] = coeff[i];
	}
}

void fill_poly_rand(Poly* p, int deg)
{
	p->deg = deg;
	p->coeff = (int*)calloc(deg + 1, sizeof(int));
	for (int i = 0; i <= deg; i++)
	{
		p->coeff[i] = (rand() % 10);
	}
}

void clean_poly(Poly* p)
{
	if (p->deg != -1)
	{
		free(p->coeff);
		p->deg = -1;
	}
}

void extend_poly(Poly* p, int new_deg)
{
	if (p->deg == new_deg) return;
	else if (p->deg < 0)
	{
		p->deg = new_deg;
		p->coeff = (int*)calloc(new_deg + 1, sizeof(int));
		for (int i = 0; i <= new_deg; i++)
		{
			p->coeff[i] = 0;
		}
	}
	else
	{
		int old_deg = p->deg;
		p->deg = new_deg;
		p->coeff = (int*)realloc(p->coeff, (new_deg + 1) * sizeof(int));
		for (int i = old_deg+1; i <= new_deg; i++)
		{
			p->coeff[i] = 0;
		}
	}
}

int evaluate_poly(Poly* p, int x)
{
	int value = 0;
	for (int i = 0; i <= p->deg; i++)
	{
		value += (int)(pow(x, i)) * p->coeff[i];
	}
	return value;
}

void sum_polly(Poly* p1, Poly* p2, Poly* p3)
{
	clean_poly(p3);
	if (p1->deg > p2->deg)
	{
		extend_poly(p3, p1->deg);
		for (int i = 0; i <= p2->deg; i++)
		{
			p3->coeff[i] = p1->coeff[i] + p2->coeff[i];
		}
		for (int i = p2->deg + 1; i <= p1->deg; i++)
		{
			p3->coeff[i] = p1->coeff[i];
		}
	}
	else if (p2->deg > p1->deg)
	{
		extend_poly(p3, p2->deg);
		for (int i = 0; i <= p1->deg; i++)
		{
			p3->coeff[i] = p1->coeff[i] + p2->coeff[i];
		}
		for (int i = p1->deg + 1; i <= p2->deg; i++)
		{
			p3->coeff[i] = p2->coeff[i];
		}
	}
	else
	{
		extend_poly(p3, p1->deg);
		for (int i = 0; i <= p2->deg; i++)
		{
			p3->coeff[i] = p1->coeff[i] + p2->coeff[i];
		}
	}
}