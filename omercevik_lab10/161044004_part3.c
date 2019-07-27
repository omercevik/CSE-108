#include <stdio.h>

int max_of_array(const int *arr, size_t arr_size, int max);
int rec(const int *arr, int value, size_t arr_size, int max);

int main()
{
	int arr[10] = {12,1,162,523,22,621,76,36,57,235};
	int res = 0;

	res = max_of_array(arr,10,arr[0]);
	printf("Index of maximum item in the array is %d and the number is %d\n",5,res );

	return 0;
}

int max_of_array(const int *arr, size_t arr_size, int max)
{
	if ( arr_size == 0 )
	{
		return max;
	}
	else
	{
		max = rec(arr,arr[0],arr_size,max);
		return max_of_array(++arr,arr_size-1,max);
	}
}

int rec(const int *arr, int value, size_t arr_size, int max)
{
	if ( arr_size == 0 )
	{
		return max;
	}
	else
	{
		if ( value > arr[0] )
		{
			max = value;
			return rec(&arr[1],value,arr_size-1,max);
		}
		else
		{
			max = arr[0];
			return rec(&arr[1],value,arr_size-1,max);
		}
	}
}