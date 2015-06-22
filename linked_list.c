#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <string.h>
#include "linked_list.h"

LL_HEAD *
new_head()
{
	LL_HEAD *head = malloc(sizeof(LL_HEAD));
	head->next = NULL;
	head->size = 0;
	head->match = NULL;
	head->free = NULL;
	return head;
}

LL_ITEM * 
new_item(void* data)
{
	LL_ITEM* item = malloc(sizeof(LL_ITEM));
	item->next = NULL;
	item->data = data;
	return item;
}

void 
free_LL(LL_HEAD* head)
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
}

void 
free_LL_ITEM(LL_ITEM* item)
{
	assert(item != NULL);
	
	free(item->data);
	free(item);
}

unsigned int 
insert_item_at(LL_HEAD* head, LL_ITEM* item, unsigned int position)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = NULL;
	LL_ITEM* prev = NULL;
	unsigned int i = 0;
	
	if(position == 0){
		prev = head->next;
		head->next = item;
		item->next = prev;
		return 0;
	}
	
	if(head->size){
		iterator = head->next;
		while(iterator != NULL && position != i)
		{
			prev = iterator;
			iterator = iterator->next;
			i++;
		}
		if(position == i){
			item->next = iterator;
		}
		prev->next = item;
	}
	else
		head->next = item;
	
	head->size++;
	return i;
}

unsigned int
remove_item(LL_HEAD* head, LL_ITEM* item)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = head->next;
	LL_ITEM* prev = NULL;
	while(iterator != NULL)
	{
		if(iterator == item){
			if(prev)
				prev->next = item->next;
			else
				head->next = item->next;
			free_LL_ITEM(item);
			head->size--;
			return 0;
		}
		prev = iterator;
		iterator = iterator->next;
	}
	return 1;
}

unsigned int 
find_position(LL_HEAD* head, LL_ITEM* item)
{
	assert(head != NULL);
	assert(item != NULL);
	
	LL_ITEM* iterator = head->next;
	unsigned int position = 0;
	
	while(iterator != item)
	{
		if(iterator->next == NULL) return 0;
		iterator = iterator->next;
		position++;
	}
	return position;
}

int 
print_LL(LL_HEAD* head)
{
	assert(head != NULL);
	
	LL_ITEM* iterator = head->next;
	
	while(iterator != NULL)
	{
		if(head->print_item){
			head->print_item(iterator);
		}
		printf("  -->  ");
		iterator = iterator->next;
	}
	return 0;
}