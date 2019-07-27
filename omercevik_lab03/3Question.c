#include <stdio.h>

void FindPrimeNumbers();

int main(void)
{
	FindPrimeNumbers();

	return 0;
}

void FindPrimeNumbers()
{
	int i, j, arr[10], prime[10], primeCounter = 0, flag = 0;

	printf("Enter 10 numbers between 0 and 1000:\n\n");

	for (i = 0; i < 10; ++i)
	{
		scanf("%d",&arr[i]);
	}

	for (j = 0; j < 10; ++j)
	{
		if (arr[j] == 1)
		{
			flag = 1;
		}
		else{
			for (i = 2; i < arr[j]; ++i)
			{
				if ( arr[j]%i == 0 )
				{
					flag = 1;
				}
			}
		}

		if ( flag == 0 )
		{
			prime[primeCounter] = arr[j];
			++primeCounter;
		}
		flag = 0;
	}

	if ( primeCounter == 0 )
	{
		printf("\nThere is not a prime number\n\n");
		FindPrimeNumbers();
	}
	else
	{
		printf("\nThe prime numbers:");
		for (i = 0; i < primeCounter; ++i)
		{
			printf("%d ",prime[i] );
		}
		printf("\n");
	}
	
}