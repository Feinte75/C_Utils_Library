#include <stdio.h>
#include "linked_list.h"

void print_int(LL_ITEM* item)
{
	printf("| data : %d |", *((int*)(item->data)));
}

int main(void)
{
	LL_HEAD *head = new_head(sizeof(int), "int");
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	LL_ITEM *i1 = new_item(&a);
	LL_ITEM *i2 = new_item(&b);
	LL_ITEM *i3 = new_item(&c);
	LL_ITEM *i4 = new_item(&d);
	LL_ITEM *i5 = new_item(&e);
	
	insert_item_at(head, i1, 4);
	insert_item_at(head, i2, 1);
	insert_item_at(head, i3, 5);
	insert_item_at(head, i4, 0);
	insert_item_at(head, i5, 0);
	printf("Position is : %d\n",find_position(head, i2));
	
	remove_item(head, i2);
	remove_item(head, i5);
	remove_item(head, i1);
	head->print_item = print_int;
	print_LL(head);
	fflush(stdout); 

	free_LL(head);
	return 0;
}