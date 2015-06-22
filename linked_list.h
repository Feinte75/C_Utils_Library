#ifndef Linked_List
#define Linked_List

#include <stdbool.h>
#define HEAD 0

typedef struct linked_list_item{
	void* data;
	struct linked_list_item *next;
}LL_ITEM;

typedef struct{
	int size;
	bool (*match)(void* a, void* b);
	void (*free)(void* data);
	void (*print_item)(LL_ITEM* item);
	LL_ITEM *next;
} LL_HEAD;

LL_HEAD *
new_head();

LL_ITEM * 
new_item(void* data);

void 
free_LL(LL_HEAD* head);

void
free_LL_ITEM(LL_ITEM* item);

unsigned int
insert_item_at(LL_HEAD* head, LL_ITEM* item, unsigned int position);

unsigned int
remove_item(LL_HEAD* head, LL_ITEM* item);

unsigned int
find_position(LL_HEAD* head, LL_ITEM* item);

int 
print_LL(LL_HEAD* head);

#endif