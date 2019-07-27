#include <stdio.h>

struct Complex
{
	double r;
	double i;
};

void addition(struct Complex a, struct Complex b);
void subtraction(struct Complex a, struct Complex b);
void multiplication(struct Complex a, struct Complex b);

int main(int argc, char const *argv[])
{
	struct Complex a, b;
	char operator;

	printf("For 1st complex number\nEnter real and imaginary part respectively: ");
	scanf("%lf %lf",&a.r,&a.i);

	printf("For 2nd complex number\nEnter real and imaginary part respectively: ");
	scanf("%lf %lf",&b.r,&b.i);

	printf("Choose your operator: ");
	scanf(" %c",&operator);

	switch(operator)
	{
		case '+': addition(a,b);
		break;

		case '-': subtraction(a,b);
		break;

		case '*': multiplication(a,b);
		break;

		default: printf("You entered not defined operation.\n");
		break;
	}
	
	return 0;
}

void addition(struct Complex a, struct Complex b)
{
	struct Complex additionRes;

	additionRes.r = a.r + b.r;
	additionRes.i = a.i + b.i;

	printf("Sum of these two complex number = %.1f + %.1fi\n",additionRes.r, additionRes.i );
}

void subtraction(struct Complex a, struct Complex b)
{
	struct Complex subtractionRes;

	subtractionRes.r = a.r - b.r;
	subtractionRes.i = a.i - b.i;

	printf("Subtraction of these two complex number = %.1f - %.1fi\n",subtractionRes.r, subtractionRes.i );
}

void multiplication(struct Complex a, struct Complex b)
{
	struct Complex multiplicationRes;

	multiplicationRes.r = (a.r * b.r)-(a.i * b.i);
	multiplicationRes.i = a.r * b.i + a.i * b.r;

	printf("Sum of these two complex number = %.1f + %.1fi\n",multiplicationRes.r, multiplicationRes.i );
}