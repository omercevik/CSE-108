#include <stdio.h>

void GrossSalaryCalculator();

int main(void)
{
	GrossSalaryCalculator();

	return 0;
}

void GrossSalaryCalculator()
{
	int BasicSalary, GrossSalary;
	double HRA, DA;

	printf("Input basic salary of an employee: ");
	scanf("%d",&BasicSalary);

	if ( BasicSalary <= 10000 )
	{
		HRA = (BasicSalary*20)/100;
		DA = (BasicSalary*80)/100;
	}
	else if ( BasicSalary >= 10001 && BasicSalary <= 20000 )
	{
		HRA = (BasicSalary*25)/100;
		DA = (BasicSalary*90)/100;
	}
	else if ( BasicSalary >= 20001 )
	{
		HRA = (BasicSalary*30)/100;
		DA = (BasicSalary*95)/100;
	}

	GrossSalary = BasicSalary + DA + HRA;

	printf("Gross salary = %d\n", GrossSalary);
}