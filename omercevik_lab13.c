#include <stdio.h>
#include <stdlib.h>

struct Dyn_arr
{
	int size;
	int limit;
	int* array;
};

void add_to_last(struct Dyn_arr *arr, int input_value);
void initArray(struct Dyn_arr *arr);
void insert_after(struct Dyn_arr *arr, int index, int input_value);

int main()
{
	struct Dyn_arr A;
	
	initArray(&A);

	for (int i = 0; i < A.limit; ++i)
	{
		printf("%d ",A.array[i] );
	}
	printf("\n");
	
	printf("Init Size  : %d\n",A.size );
	printf("Init Limit : %d\n",A.limit );

	printf("\n");

	add_to_last(&A,0);
	add_to_last(&A,1);
	add_to_last(&A,2);
	add_to_last(&A,3);
	add_to_last(&A,4);
	add_to_last(&A,5);
	add_to_last(&A,6);
	add_to_last(&A,7);
	add_to_last(&A,8);
	add_to_last(&A,9);
	add_to_last(&A,10);
	add_to_last(&A,11);
	add_to_last(&A,12);
	add_to_last(&A,13);
	add_to_last(&A,14);


	for (int i = 0; i < A.size; ++i)
	{
		printf("%d ",A.array[i] );
	}

	printf("\n");
	printf("Size  : %d\n",A.size );
	printf("Limit : %d\n",A.limit );

	printf("\n");
	insert_after(&A,-1,100);

	for (int i = 0; i < A.size; ++i)
	{
		printf("%d ",A.array[i] );
	}

	printf("\nSize  : %d\n",A.size );
	printf("Limit : %d\n",A.limit );
	
	free(A.array);
	return 0;
}

void insert_after(struct Dyn_arr *arr, int index, int input_value)
{
	if ( arr->limit - arr->size > 0 )
	{
		int i = 0, j = 0;
		++arr->size;
		int* tempArr = (int*)calloc(arr->size,sizeof(int));

		for (i = 0; i < arr->size; ++i)
		{
			if ( i == index )
			{
				tempArr[i] = input_value;
			}
			else
			{
				tempArr[i] = arr->array[j];
				++j;
			}
		}

		free(arr->array);
		arr->array = (int*)calloc(arr->size,sizeof(int));

		for (int i = 0; i < arr->size; ++i)
		{
			arr->array[i] = tempArr[i];
		}

		free(tempArr);
	}
	else if ( arr->limit == arr->size )
	{
		int i = 0, j = 0;
		++arr->size;
		arr->limit += 5;
		int* tempArr = (int*)calloc(arr->limit,sizeof(int));

		for (i = 0; i < arr->size; ++i)
		{
			if ( i-1 == index )
			{
				tempArr[i] = input_value;
			}
			else
			{
				tempArr[i] = arr->array[j];
				++j;
			}
		}

		free(arr->array);
		arr->array = (int*)calloc(arr->limit,sizeof(int));

		for (int i = 0; i < arr->size; ++i)
		{
			arr->array[i] = tempArr[i];
		}

		free(tempArr);
	}
}

void initArray(struct Dyn_arr *arr)
{
	arr->size = 0;
	arr->array = (int*)calloc(5,sizeof(int));
	arr->limit = 5;
}

void add_to_last(struct Dyn_arr *arr, int input_value)
{
	if ( arr->limit - arr->size > 0 )
	{
		arr->array[arr->size] = input_value; 
		++arr->size;
	}
	else if ( arr->limit == arr->size )
	{
		int* tempArr = (int*)calloc(5+arr->size,sizeof(int));
		int i = 0;

		for (i = 0; i < arr->size; ++i)
		{
			tempArr[i] = arr->array[i];
		}

		free(arr->array);

		arr->array = (int*)calloc(5+arr->size,sizeof(int));

		for (i = 0; i < arr->size; ++i)
		{
			arr->array[i] = tempArr[i];
		}

		arr->limit += 5;
		arr->array[arr->size] = input_value;
		++arr->size;
		free(tempArr);
	}
}