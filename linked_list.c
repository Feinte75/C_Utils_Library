#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>

#define BEGIN 0

typedef struct linked_list_item LL_ITEM;
struct linked_list_item{
	
	char* data;
	struct linked_list_item *next;
};

typedef struct linked_list_head LL_HEAD;
struct linked_list_head{
	int size;
	LL_ITEM *next;
};


LL_ITEM* new_item(char* data)
{
	LL_ITEM* item = malloc(sizeof(LL_ITEM));
	item->next = NULL;
	item->data = data;
	return item;
}

LL_HEAD *new_head()
{
	LL_HEAD *head = malloc(sizeof(LL_HEAD));
	head->next = NULL;
	return head;
}

int add_item(LL_HEAD** head, LL_ITEM* item, int position)
{
	LL_ITEM* iterator = NULL;
	int i = 0;
	
	assert(head != NULL);
	assert(item != NULL);
	
	if((*head)->next == NULL){
		(*head)->next = item;
		return 1;
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
	return 1;
}

static inline LL_ITEM* add_last(LL_HEAD** head, LL_ITEM* item)
{
	return NULL;
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

int print_LL(LL_HEAD** head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = (*head)->next;
	
	while(iterator != NULL)
	{
		printf("| data : %s |", iterator->data);
		printf("  -->  ");
		iterator = iterator->next;
	}
	
	return 1;
}

int main(int args, char* argv[])
{
	LL_HEAD *head = new_head();
	LL_ITEM *i1 = new_item("i1");
	LL_ITEM *i2 = new_item("i2");
	LL_ITEM *i3 = new_item("i3");
	
	add_item(&head, i1, 1);
	add_item(&head, i2, 2);
	add_item(&head, i3, 0);
	printf("Position is : %d\n",find_position(&head, i2));
	print_LL(&head);
	fflush(stdout); 
	//getchar();
	free(head);
	free(i1);
	free(i2);
	return 0;
}