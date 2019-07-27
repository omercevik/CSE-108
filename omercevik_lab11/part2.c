#include <stdio.h>

int rec(int n, int sum);

int main()
{
	int n = 0;

	printf("Enter n = ");
	scanf("%d",&n);

	for (int i = 1; i <= n; ++i)
	{
		printf("%d",rec(i,0));
		printf("\n");
	}

	return 0;
}

int rec(int n, int sum)
{
	if ( n == 1 )
	{
		return 3;
	}
	else if ( n == 2 )
	{
		return 5;
	}
	else
	{
		if ( n%2 == 0 && n != 2 )
		{
			return rec(n-2,n)+rec(n-1,n);
		}
		else if ( n%2 != 0 && n != 1 )
		{
			return -rec(n-2,n)+rec(n-1,n);
		}
	}
}