#include <stdio.h>
#include "linked_list.h"

void print_int(LL_ITEM* item)
{
	printf("| data : %d |", *((int*)(item->data)));
}

int main(void)
{
	LL_HEAD *head = new_head(sizeof(int), "int");
	int a = 1, b = 2, c = 3;
	LL_ITEM *i1 = new_item(&a);
	LL_ITEM *i2 = new_item(&b);
	LL_ITEM *i3 = new_item(&c);
	
	insert_item_at(head, i1, 1);
	insert_item_at(head, i2, 2);
	insert_item_at(head, i3, 0);
	printf("Position is : %d\n",find_position(head, i2));
	head->print_item = print_int;
	print_LL(head);
	fflush(stdout); 

	free_LL(head);
	return 0;
}