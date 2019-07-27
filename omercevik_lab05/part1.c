#include <stdio.h>

void LCMGCD(int* a, int* b);

int main()
{
	int x,y,a,b;

	printf("Enter a number: \n");
	scanf("%d",&x);
	printf("Enter a number: \n");
	scanf("%d",&y);

	a = x;
	b = y;

	LCMGCD(&x,&y);

	printf("LCMGCD(%d,%d) = %d,%d\n",a,b,y,x );

	return 0;
}

void LCMGCD(int* a, int* b)
{
	int min = 0, i, tempa = *a, tempb = *b, gcd = 1;

	if ( *a < *b)
	{
		min = *a;
	}
	else
	{
		min = *b;
	}

	for (i = 2; i < min; ++i)
	{
		while ( tempa%i == 0 && tempb%i == 0 )
		{
			tempa /= i;
			tempb /= i;
			gcd *= i;
		}
	}

	*a = gcd;
	*b = gcd*tempb*tempa;
}