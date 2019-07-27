#include <stdio.h>

void switchCalculator();

int main(void)
{
	switchCalculator();

	return 0;
}

void switchCalculator()
{
	double x, y;
	char sign;

	printf("Enter an operator(+,-,*,/):");
	scanf("%c",&sign);
	printf("Enter two operands:");
	scanf("%lf %lf", &x, &y);

	switch(sign)
	{
		case '+': printf("%.1f+%.1f = %.1f\n",x ,y, x + y );
		break;

		case '-': printf("%.1f-%.1f = %.1f\n",x ,y, x - y );
		break;

		case '*': printf("%.1f*%.1f = %.1f\n",x ,y, x * y );
		break;

		case '/': if( y != 0 ){ printf("%.1f/%.1f = %.1f\n",x ,y, x / y ); }else { printf("Unacceptable value is 0 for second operand.\n");}
		break;
	}
}