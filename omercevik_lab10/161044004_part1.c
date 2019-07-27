#include <stdio.h>

int lcm(int number_1, int number_2, int largest);

int main()
{
	int a = 24, b = 36, c = 1, tempA = 0, tempB = 0;

	printf("Enter two integer numbers for calculate the LCM of numbers: ");
	scanf("%d%d",&a,&b);

	tempA = a;
	tempB = b;

	if ( a == 0 || b == 0 )
	{
		printf("Unacceptable 0 values.\n");
	}
	else if ( a == 1 )
	{
		printf("LCM of %d and %d is %d.\n", a, b, b );
	}
	else if ( b == 1 )
	{
		printf("LCM of %d and %d is %d.\n", a, b, a );
	}
	else
	{
		c = lcm(a,b,c);
		printf("LCM of %d and %d is %d.\n",tempA,tempB,c );
	}

	return 0;
}

int lcm(int number_1, int number_2, int largest)
{
	if ( number_1 == 1 && number_2 == 1 )
	{
		return largest;
	}
	else
	{
		if ( number_1 == 1 && number_2 != 1 )
		{
			return lcm(number_1,number_2/number_2,largest*number_2);
		}
		else if ( number_2 == 1 && number_1 != 1 )
		{
			return lcm(number_1/number_1,number_2,largest*number_1);
		}
		else
		{
			if ( number_1%2 == 0 && number_2%2 == 0 )
			{
				return lcm(number_1/2,number_2/2,largest*2);
			}
			else if ( number_1%3 == 0 && number_2%3 == 0 )
			{
				return lcm(number_1/3,number_2/3,largest*3);
			}
			else if ( number_1%5 == 0 && number_2%5 == 0 )
			{
				return lcm(number_1/5,number_2/5,largest*5);
			}
			else
			{
				if ( number_1%2 == 0 && number_2%2 != 0 )
				{
					return lcm(number_1/2,number_2,largest*2);
				}
				else if ( number_1%2 != 0 && number_2%2 == 0 )
				{
					return lcm(number_1,number_2/2,largest*2);
				}
				else if ( number_1%3 == 0 && number_2%3 != 0 )
				{
					return lcm(number_1/3,number_2,largest*3);
				}
				else if ( number_1%3 != 0 && number_2%3 == 0 )
				{
					return lcm(number_1,number_2/3,largest*3);
				}
				else if ( number_1%5 == 0 && number_2%5 != 0 )
				{
					return lcm(number_1/5,number_2,largest*5);
				}
				else if ( number_1%5 != 0 && number_2%5 == 0 )
				{
					return lcm(number_1,number_2/5,largest*5);
				}
			}
		}
	}
}