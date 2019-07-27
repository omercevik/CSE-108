#include <stdio.h>

int sumofPrimeCheck(int p, int *last1, int *last2);
int primeCheck(int x);

int main()
{
	int num = 0, last1 = 0, last2 = 0;

	printf("Enter a positive integer = ");
	scanf("%d",&num);
	printf("\n");

	if (sumofPrimeCheck(num,&last1,&last2) == 1 )
	{
		printf("Last values are : %d,%d\n",last1,last2);
	}
	
	return 0;
}

int sumofPrimeCheck(int p, int *last1, int *last2)
{
	int i = 0, flag = 0;

	if ( p == 1 )
	{
		printf("The number is not expressed as the sum of two prime numbers.\n");
		return 0;
	}
	else 
	{
		for (i = 2; i < p/2+1; ++i)
		{
			if ( (primeCheck(i) == 1) && (primeCheck(p-i) == 1) )
			{
				printf("%d=%d+%d\n\n",p,i,p-i );
				flag = 1;
			}
		}

		*last1 = i-1;
		*last2 = p-i+1;

		if ( flag == 0 )
		{
			printf("The number is not expressed as the sum of two prime numbers.\n");
			return 0;
		}

		return 1;
	}
}

int primeCheck(int x)
{
	int i = 0, flag = 1;

	for (i = 2; i <= x/2; ++i)
	{
		if ( x%i == 0 )
		{
			flag = 0;
			return 0;
		}
	}

	if ( flag == 1 )
	{
		return 1;
	}
}