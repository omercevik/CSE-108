#include <stdio.h>
#include <math.h>

void welcome(void);
int getHeight(void);
double getInputDouble(void);
double calculateBMI(int height, double weight);
void printBMICategory(double bmi);
void printInfo(int height, double weight);

int main()
{
	int cm = 0;
	double kg = 0.0;
	double calculatedBMI = 0.0;

	welcome();
	cm = getHeight();
	kg = getInputDouble();
	calculatedBMI = calculateBMI(cm,kg);
	printBMICategory(calculatedBMI);
	
	printInfo(172,80.0);

	return 0;
}

void welcome(void)
{
	printf("---------- BMI Calculator ----------\n");
}

int getHeight(void)
{
	int scanHeight = 0;

	printf("Enter height (in cm): ");
	scanf("%d",&scanHeight);

	return scanHeight;
}

double getInputDouble(void)
{
	double scanWeight = 0.0;

	printf("Enter the weight (in kg): ");
	scanf("%lf",&scanWeight);

	return scanWeight;
}

double calculateBMI(int height, double weight)
{
	return weight/(pow((double)height/100.0,2.0));
}

void printBMICategory(double bmi)
{
	if ( bmi >= 0 && bmi <= 18.49 )
	{
		printf("Category: Underweight\n");
	}
	else if ( bmi >= 18.5 && bmi <= 24.49 )
	{
		printf("Category: Normal\n");
	}
	else if ( bmi >= 24.5 && bmi <= 29.99 )
	{
		printf("Category: Overweight\n");
	}
	else if ( bmi >= 30 )
	{
		printf("Category: Obesity\n");
	}
}

void printInfo(int height, double weight)
{
	printf("Height: %d cm\n",height );
	printf("Weight: %.1f kg\n",weight );
	printf("BMI: %.2f kg/m2\n",calculateBMI(height,weight) );
	printBMICategory(calculateBMI(height,weight));
}