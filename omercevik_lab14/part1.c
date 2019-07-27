#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node * next;
} node_t;

int main()
{
	int i = 0, x = 0;
	node_t* head = (node_t*)malloc(sizeof(node_t));
	node_t* tempRoot = (node_t*)malloc(sizeof(node_t));
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	tempRoot = head;

	for (i = 0; i < 5; ++i)
	{
		head->next = (node_t*)malloc(sizeof(node_t));
		head = head->next;
	}
	head->next = NULL;
	head = tempRoot;

	printf("list: ");
	
	while (head != NULL)
	{
		scanf("%d",&head->val);
		head = head->next;
	}
	head = tempRoot;

	printf("x = ");
	scanf("%d",&x);

	while( head->next != NULL )
	{
		if ( head->val > x )
		{
			temp = head->next;
			free(head);
			head = temp;
		}
		else if ( head->val > x && head->next == NULL )
		{
			free(head);
			head = NULL;
		}
		else if ( head->next->val > x && head->next->next != NULL )
		{
			temp = head->next->next;
			free(head->next);
			head->next = temp;
			head = head->next;
		}
		else
		{
			head = head->next;
		}
		if ( head != NULL)
		{
			printf("%d->",head->val );
		}
	}
	printf("\n");

	return 0;
}