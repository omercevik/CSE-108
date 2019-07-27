#include <stdio.h>
#include <stdlib.h>

struct Signt
{
	struct Signt* next;
	struct Signt* prev;
	int data;
};

void calculate(struct Signt* header );

int main(int argc, char const *argv[])
{
	struct Signt* root = (struct Signt*)malloc(sizeof(struct Signt));

	calculate(root);

	return 0;
}

void calculate(struct Signt* header )
{
	int sum = 0, signNum = 0, j = 0;
	struct Signt* temp = (struct Signt*)malloc(sizeof(struct Signt));
	temp = header;

	for (signNum = 0; signNum <= 1000; ++signNum)
	{
		for (j = 1; j < signNum; ++j)
		{
			if ( signNum%j == 0 )
			{
				sum += j;
			}
		}

		if ( sum == signNum && sum != 0 )
		{
			printf("%d = ",signNum );

			header->data = sum;

			for (j = 1; j < signNum; ++j)
			{
				if ( signNum%j == 0 )
				{
					printf("%d + ",j );
				}
			}
			printf("\n");
			header->next = (struct Signt*)malloc(sizeof(struct Signt));
			header = header->next;
		}
		header->next = NULL;
		sum = 0;
	}
	header = temp;
	header->prev = NULL;

	while( header->next != NULL )
	{
		printf("%d \n",header->data );
		header->next->prev = (struct Signt*)malloc(sizeof(struct Signt));
		header->next->prev = header;
		header = header->next;
	}

	while( header != NULL )
	{	
		if ( header->data != 0 )
		{
			printf("%d \n",header->data );
		}
		header = header->prev;
	}
}