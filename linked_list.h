#ifndef Linked_List
#define Linked_List

#define HEAD 0

typedef struct linked_list_item LL_ITEM;
struct linked_list_item;

typedef struct linked_list_head LL_HEAD;
struct linked_list_head{
	int size;
	int data_size;
	char* data_description;
	LL_ITEM *next;
};

#endif