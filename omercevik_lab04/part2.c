#include <stdio.h>

void drawHexagon(int n);

int main()
{
	int n;
	scanf("%d",&n);

	drawHexagon(n);
	return 0;
}

void drawHexagon(int n)
{
	int i = 0, j = 0, a = n, k = 0, b = n;
	
	if ( n == 1 )
	{
		printf("*\n");
	}
	else
	{
		for (i = 0; i < n; ++i)
		{
			for (j = a-1; j > 0; --j)
			{
				printf(" ");
			}
			--a;
			for (k = 0; k < b; ++k)
			{
				printf("*");
			}
			b+=2;
			printf("\n");
		}

	}
}