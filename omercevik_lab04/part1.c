#include <stdio.h>

void SumValue(int x);

int main(void)
{
	int x;

	scanf("%d",&x);

	SumValue(x);
	
	return 0;
}

void SumValue(int x)
{
	if ( x == 1 )
	{
		printf("1=1\n\n");
	}
	else
	{
		SumValue(x-1);
		printf("1+%d=%d\n\n",x,1+x);
	}
}