#include <stdio.h>

void Fibonacci(int num, int *counter, int *max);

int main()
{
	int number = 0, counter = 2, max = 0;
	printf("Enter number: ");
	scanf("%d", &number);

	Fibonacci(number,&counter,&max);

	printf("\n");

	printf("Number of the integer and the biggest number in the Fibonacci Series: %d,%d\n",counter,max );
	return 0;
}

void Fibonacci(int num, int *counter, int *max)
{
	int sum = 0, n1 = 0, n2 = 1;
	printf("%d,%d,",n1 , n2 );
	while( num >= sum )
	{
		if ( n1+n2 >= num )
		{
			*max = sum;
			break;
		}
		else
		{
			sum = n1+n2;
			n1 = n2;
			n2 = sum;
			++(*counter);
			printf("%d,",sum );
		}
	}	
}