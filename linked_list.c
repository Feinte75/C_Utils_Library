#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <string.h>
#include "linked_list.h"

LL_HEAD *new_head(int data_size, char* data_description)
{
	LL_HEAD *head = malloc(sizeof(LL_HEAD));
	head->next = NULL;
	head->size = 0;
	head->match = NULL;
	head->free = NULL;
	head->data_size = data_size;
	head->data_description = data_description;
	return head;
}

LL_ITEM* new_item(void* data)
{
	LL_ITEM* item = malloc(sizeof(LL_ITEM));
	item->next = NULL;
	item->data = data;
	return item;
}

int free_LL(LL_HEAD* head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = head->next;
	LL_ITEM* delete;
	
	while(iterator != NULL)
	{
		delete = iterator;
		iterator = iterator->next;
		if(head->free)
			head->free(delete->data);
		
		free_LL_ITEM(delete);
	}
	free(head);
	return 0;
}

int free_LL_ITEM(LL_ITEM* item)
{
	free(item->data);
	free(item);
	return 0;
}

int insert_item_at(LL_HEAD* head, LL_ITEM* item, unsigned int position)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = NULL;
	unsigned int i = 0;
	
	if(head->size){
		iterator = head->next;
		while(iterator->next != NULL && position != i)
		{
			iterator = iterator->next;
			i++;
		}
		if(position == i)
			item->next = iterator->next;
		
		iterator->next = item;
			
	}
	else
		head->next = item;
	
	head->size++;

	return 0;
}

unsigned int find_position(LL_HEAD* head, LL_ITEM* item)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = head->next;
	unsigned int position = 0;
	
	while(iterator != item)
	{
		if(iterator->next == NULL) return -1;
		iterator = iterator->next;
		position++;
	}
	return position;
}

int print_LL(LL_HEAD* head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = head->next;
	
	while(iterator != NULL)
	{
		//printf("| data : %s |", iterator->data);
		if(head->print_item){
			head->print_item(iterator);
		}
		printf("  -->  ");
		iterator = iterator->next;
	}
	return 0;
}