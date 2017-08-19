#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
	int data;
	struct elementT *next;
} element;

int insert_singlylinkedlist(element **head, int data)
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
		new->data = data;
		new->next = *head;
		*head = new;
		return 0;
	}
}

element *find_singlylinkedlist(element *head, int value)
{
	while(head)
	{
		if(head->data == value) return head;
		head = head->next;
	}
	return NULL;
}

void display_singlylinkedlist(element *head)
{
	int linknumber = 0;

	while(head)
	{
		printf("%d %d\n", linknumber++, head->data);
		head = head->next;
	}
}

int main()
{
	element *head = 0;
	int status;

	display_singlylinkedlist(head);
	
	status = insert_singlylinkedlist(&head, 2);
	status = insert_singlylinkedlist(&head, 3);
	printf("element with %d is at %p\n", 5, find_singlylinkedlist(head, 5));
	status = insert_singlylinkedlist(&head, 4);
	status = insert_singlylinkedlist(&head, 5);
	printf("element with %d is at %p %d\n", 5, find_singlylinkedlist(head, 5), find_singlylinkedlist(head, 5)->data);
	if(status)
	{
		printf("%s %d fail to insert new\n", __FILE__, __LINE__);
		return -1;
	}
	
	display_singlylinkedlist(head);
}