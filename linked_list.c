#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <string.h>

#define HEAD 0

typedef struct linked_list_item LL_ITEM;
struct linked_list_item{
	void* data;
	struct linked_list_item *next;
};

typedef struct linked_list_head LL_HEAD;
struct linked_list_head{
	int size;
	int data_size;
	char* data_description;
	LL_ITEM *next;
};


LL_ITEM* new_item(void* data)
{
	LL_ITEM* item = malloc(sizeof(LL_ITEM));
	item->next = NULL;
	item->data = data;
	return item;
}

LL_HEAD *new_head(int data_size, char* data_description)
{
	LL_HEAD *head = malloc(sizeof(LL_HEAD));
	head->next = NULL;
	head->size = 0;
	head->data_description = data_description;
	return head;
}

int add_item(LL_HEAD** head, LL_ITEM* item, int position)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = NULL;
	int i = 0;
	
	if((*head)->next == NULL){
		(*head)->next = item;
		return 0;
	}
	else if(position == HEAD){
		item->next = (*head)->next;
		(*head)->next = item;
		return 0;
	}
	else iterator = (*head)->next;

	while(iterator->next != NULL && position != i)
	{
		iterator = iterator->next;
		i++;
	}
	
	if(iterator->next != NULL){
		item->next = iterator->next;
	}
	iterator->next = item;
	(*head)->size ++;
	
	return 0;
}

int find_position(LL_HEAD** head, LL_ITEM* item)
{
	assert(head != NULL);
	assert(*head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = (*head)->next;
	int position = 0;
	
	while(iterator != item)
	{
		if(iterator->next == NULL) return -1;
		iterator = iterator->next;
		position++;
	}
	
	return position;
}

int free_LL_ITEM(LL_ITEM* item)
{
	free(item->data);
	free(item);
	return 0;
}

int free_LL(LL_HEAD** head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = (*head)->next;
	LL_ITEM* delete;
	
	while(iterator != NULL)
	{
		delete = iterator;
		iterator = iterator->next;
		free_LL_ITEM(delete);
	}
	free(*head);
	return 0;
}

int print_LL(LL_HEAD** head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = (*head)->next;
	
	char format[100];
	if(strcmp((*head)->data_description, "string") == 0)snprintf(format,100, "%s %s %s", "| data:", "%s", " |");
	else if(strcmp((*head)->data_description, "int") == 0)snprintf(format,100, "%s %s %s", "| data:", "%d", " |");
	else if(strcmp((*head)->data_description, "bin") == 0)snprintf(format,100, "%s %s %s", "| data:", "%h", " |");

	
	while(iterator != NULL)
	{
		//printf("| data : %s |", iterator->data);
		printf(format, *(iterator->data));
		printf("  -->  ");
		iterator = iterator->next;
	}
	
	return 0;
}

int main(int args, char* argv[])
{
	LL_HEAD *head = new_head(sizeof(char*), "int");
	int a = 1, b = 2, c = 3;
	LL_ITEM *i1 = new_item(&a);
	LL_ITEM *i2 = new_item(&b);
	LL_ITEM *i3 = new_item(&c);
	
	add_item(&head, i1, 1);
	add_item(&head, i2, 2);
	add_item(&head, i3, 0);
	printf("Position is : %d\n",find_position(&head, i2));
	print_LL(&head);
	fflush(stdout); 
	//getchar();
	free_LL(&head);
	return 0;
}