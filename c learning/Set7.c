#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>

struct slinked
{
	int value;
	struct slinked* next;
};

struct slinkedrep
{
	struct slinked* head;
	struct slinked* curr;
};

struct slinked* create_element()
{
	int x;
	printf("\n\nPut the value of element: ");
	if (scanf("%d", &x) == 1)
	{
		struct slinked* new_element = NULL;
		new_element = (struct slinked*)malloc(sizeof(struct slinked));
		new_element->value = x;
		return new_element;
	}
	return NULL;
}

struct slinked* create_element_with_value(int value)
{
	struct slinked* new_element = NULL;
	new_element = (struct slinked*)malloc(sizeof(struct slinked));
	new_element->value = value;
	new_element->next = NULL;
	return new_element;
}

void printel(struct slinked* x)
{
	printf("\n%d", x->value);
}

void printlist(struct slinked* x)
{
	while (x != NULL)
	{
		printf("\n%d", x->value);
		x = x->next;
	}
}

struct slinked* insert_at_begining(struct slinked* head, struct slinked* target)
{
	target->next = head;
	head = target;
	return head;
}

void destroy_list(struct slinked* head)
{
	while (head != NULL)
	{
		struct slinked* x = head;
		head = head->next;
		free(x);
	}
}

void insert_at_end(struct slinked* head, struct slinked* new_last)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	new_last->next = NULL;
	head->next = new_last;
}

struct slinked* delete_first(struct slinked* head)
{
	struct slinked* tmp = head->next;
	free(head);
	return tmp;
}

void delete_last(struct slinked* head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	struct slinked* tmp = head;
	free(head);
	tmp->next = NULL;
}

int find_first(struct slinked* head, int find)
{
	int i = 1;
	while (head != NULL && (int)head->value != find)
	{
		i++;
		head = head->next;
	}
	if (head != NULL) return i;
	else return 0;
}


void Set7(int chosenTask)
{
	struct slinked* head = create_element_with_value(1);
	struct slinked* second = create_element_with_value(4); insert_at_end(head, second);
	struct slinked* third = create_element_with_value(4); insert_at_end(head, third);
	struct slinked* fourth = create_element_with_value(8); insert_at_end(head, fourth);
	struct slinked* fifth = create_element_with_value(16); insert_at_end(head, fifth);
	struct slinked* sixth = create_element_with_value(32); insert_at_end(head, sixth);

	switch (chosenTask)
	{
	case 1:
		struct slinked* new_el1 = create_element();
		printel(new_el1);
		free(new_el1);
		break;
	case 2:
		printel(head);
		break;
	case 3:
		printlist(head);
		struct slinked* new_el3 = create_element();
		head = insert_at_begining(head, new_el3);
		printlist(head);
		break;
	case 4:
		//function call below switch
		break;
	case 5:
		// print all elements and after some is basically the same 
		printlist(second);
		break;
	case 6:
		printlist(head);
		break;
	case 7:
		struct slinked* new_el7 = create_element();
		insert_at_end(head, new_el7);
		printlist(head);
		break;
	case 8:
		head = delete_first(head);
		printlist(head);
		break;
	case 9:
		delete_last(head);
		printlist(head);
		break;
	case 10:
		int x10;
		printf("\nPut value you want to find: ");
		if (scanf("%d", &x10) == 1)
		{
			if (find_first(head, x10) != 0) printf("\nFirst occurance of this value is at position %d", find_first(head, x10));
			else printf("\nThre is no such character in the list!");
		}
		break;
	default:
		printf("There is no such Task!");
		break;
	}
	destroy_list(head);
}