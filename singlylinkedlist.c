#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
	int data;
	struct elementT *next;
} element;


/*
insert new data to head in singly linked list
*/
int insert_data_head_sllist(element **head, int data)
{
	element *new;
	new = (element *) malloc(sizeof(element));
	if(!new)
	{
		printf("%s %d fail to allocate memory\n", __FILE__, __LINE__);
		return -1;
	}
	else
	{
		printf("add %p\n", new);
		new->data = data;
		new->next = *head;
		*head = new;
		return 0;
	}
}

/*
find data in singly linked list
*/
element *find_data_sllist(element *head, int value)
{
	while(head)
	{
		if(head->data == value) return head;
		head = head->next;
	}
	return NULL;
}

/*
display data of singly linked list
*/
void display_data_sllist(element *head)
{
	int linknumber = 0;

	while(head)
	{
		printf("%d %d\n", linknumber++, head->data);
		head = head->next;
	}
}

/*
delete singly linked list
*/
int delete_sllist(element *head)
{
	element *next;
	element *delete = head;

	while(delete)
	{
		next = delete->next;
		free(delete);
		printf("delete %p\n", delete);
		delete = next;
	}
}

/*
delete node singly linked list
*/
int delete_data_sllist(element **head, element *deleteme)
{
	element *curr = *head;

	if(*head == deleteme)
	{
		*head = deleteme->next;
		free(deleteme);
		printf("delete %p\n", deleteme);
		return 1;
	}
	while(curr)
	{
		if(curr->next == deleteme)
		{
			curr->next = deleteme->next;
			free(deleteme);
			printf("delete %p\n", deleteme);
			return 1;
		}
		else
			curr = curr->next;
	}
	return 0; 

}

int main()
{
	element *head = 0;
	element *ele;
	int status;

	display_data_sllist(head);
	
	status = insert_data_head_sllist(&head, 2);
	status = insert_data_head_sllist(&head, 3);
	status = insert_data_head_sllist(&head, 4);
	status = insert_data_head_sllist(&head, 5);
	printf("element with %d is at %p %d\n", 3, find_data_sllist(head, 3), find_data_sllist(head, 3)->data);
	if(status)
	{
		printf("%s %d fail to insert new\n", __FILE__, __LINE__);
		return -1;
	}
	ele = find_data_sllist(head, 3);
	delete_data_sllist(&head, ele);
	display_data_sllist(head);
	delete_sllist(head);
}