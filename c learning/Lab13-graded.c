#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABEL_LENGTH 63

typedef struct {
	char string[MAX_LABEL_LENGTH];
	int length;
} Label;

typedef struct LE {
	Label label;
	struct LE* prev;
	struct LE* next;
} ListElement;

typedef struct {
	ListElement* head;
	ListElement* tail;
} List;

void PrintLabel(const Label* label) {
	printf("%s.%d ", label->string, label->length);
}

Label SetLabel(const char* label);

ListElement* CreateElement(const char* str);

void InsertFirst(ListElement* el, List* list);

void PrintList(const List* list);

void DeleteList(List* list);

int LabelsLength(List* list);

void BuildLabelsList(List* list, const char* letters);

int InList(const List* list, Label label);

List CommonLabels(const List* a, const List* b);

void version_a13();
void version_b13();

void Lab13(void)
{
	int choice;
	printf("\nChoose version ( A - 1  B - 2 ): ");
	if (scanf("%d", &choice) == 1)
	{
		switch (choice)
		{
		case 1:
			version_a13();
			break;
		case 2:
			version_b13();
			break;
		default:
			break;
		}
	}
}

void version_a13()
{
	Label tmp_label;
	ListElement* le;
	puts("------ PART 1 ------");
	tmp_label = SetLabel("test");

	printf("Label \"%s\" has %d  characters", tmp_label.string, tmp_label.length);
	printf("\nPrintLabel : ");
	PrintLabel(&tmp_label);

	le = CreateElement("First");
	printf("\nPrintLabel for element : ");
	PrintLabel(&le->label);

	puts("\n------ PART 2 ------");
	List mylist = { NULL,NULL };
	InsertFirst(le, &mylist);
	InsertFirst(CreateElement("Next one"), &mylist);
	printf("List: ");
	PrintList(&mylist);
	DeleteList(&mylist);
	
	puts("\n------ PART 3 ------");
	char str[80];
	strcpy(str, "abc");
	BuildLabelsList(&mylist, str);
	PrintList(&mylist);
	printf("Total length of labels = %d\n", LabelsLength(&mylist));
	DeleteList(&mylist);
	PrintList(&mylist);

	puts("\n------ PART 4 ------");
	{
		List list1 = { NULL,NULL };
		List list2 = { NULL,NULL };
		List list3 = { NULL,NULL };

		strcpy(str, "xyz");
		BuildLabelsList(&list1, str);
		PrintList(&list1);
		printf("Total length of labels = %d\n", LabelsLength(&list1));

		strcpy(str, "xyy");
		BuildLabelsList(&list2, str);
		PrintList(&list2);
		printf("Total length of labels = %d\n", LabelsLength(&list2));

		list3 = CommonLabels(&list1, &list2);
		puts("\nCommon labels");
		PrintList(&list3);
		printf("Total length of labels = %d", LabelsLength(&list3));

		DeleteList(&list1);
		DeleteList(&list2);
		DeleteList(&list3);
	}

	puts("\nBye!");
}

void version_b13()
{

}

Label SetLabel(const char* label)
{
	Label new_label;
	strcpy(new_label.string, label);
	new_label.length = (int)strlen(new_label.string);
	return new_label;
}

ListElement* CreateElement(const char* str)
{
	ListElement* new_element = (ListElement*)malloc(sizeof(ListElement));
	new_element->label = SetLabel(str);
	new_element->next = NULL;
	new_element->prev = NULL;
	if (new_element)
	{
		return new_element;
	}
	return NULL;
}

void InsertFirst(ListElement* el, List* list)
{
	if (list->head)
	{
		list->head->prev = el;
		el->next = list->head;
		list->head = el;
	}
	else
	{
		list->head = el;
		list->tail = el;
	}
}

void PrintList(const List* list)
{
	ListElement* temp = list->head;
	while (temp)
	{
		PrintLabel(&temp->label);
		temp = temp->next;
	}
}

void DeleteList(List* list) 
{
	//ListElement* current = list->head;
	list->head = NULL;
	list->tail = NULL;
	/*while (current != NULL)
	{
		ListElement* temp = current;
		current = current->next;
		free(temp);
	}*/
	
}

int LabelsLength(List* list)
{
	int sum = 0;
	ListElement* temp = list->head;
	while (temp)
	{
		sum += temp->label.length;
		temp = temp->next;
	}
	return sum;
}

void BuildLabelsList(List* list, const char* letters)
{
	char str[4];
	str[3] = '\0';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				str[0] = letters[i];
				str[1] = letters[j];
				str[2] = letters[k];
				ListElement* a = CreateElement(str);
				InsertFirst(a, list);
			}
		}
	}
}

int InList(const List* list, Label label)
{
	ListElement* temp = list->head;
	while (temp)
	{
		if (!strcmp(temp->label.string, label.string))
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

List CommonLabels(const List* a, const List* b)
{
	List new_list = {NULL,NULL};
	ListElement* first = b->tail;
	while (first)
	{
		if ((InList(a, first->label)) && (!InList(&new_list, first->label)))
		{
			InsertFirst(first, &new_list);
		}
		first = first->prev;
	}
	new_list.head->prev = NULL;
	new_list.tail->next = NULL;
	return new_list;
}