#include <stdio.h>

struct student
{
	char name[100];
	char surname[100];
	double q1;
	double q2;
	double midterm;
	double final;
	double score;
};

int main()
{
	struct student s[10];
	int i = 0, j = 0;
	double avgQuiz1 = 0.0, avgQuiz2 = 0.0, avgMidterm = 0.0, avgFinal = 0.0, avgAll = 0.0;
	char c = 'y';

	while(i < 10 && c == 'y')
	{
		printf("Enter the student's name: ");
		scanf("%s%s",s[i].name,s[i].surname);
		printf("\n");
		printf("Enter the student's grade for quiz #1: ");
		scanf("%lf",&s[i].q1);
		printf("\n");
		printf("Enter the student's grade for quiz #2: ");
		scanf("%lf",&s[i].q2);
		printf("\n");
		printf("Enter the student's grade for midterm: ");
		scanf("%lf",&s[i].midterm);
		printf("\n");
		printf("Enter the student's grade for final: ");
		scanf("%lf",&s[i].final);
		printf("\n");

		s[i].score = (s[i].q1*10 + s[i].q2*10)/8 + s[i].midterm/4 + s[i].final/2;

		avgQuiz1 += s[i].q1;
		avgQuiz2 += s[i].q2;
		avgMidterm += s[i].midterm;
		avgFinal += s[i].final;

		printf("%s %s's numeric score for the entire course is %.2f\n",s[i].name,s[i].surname,s[i].score );
	
		printf("\nWould you like to enter another student record? y(yes) or n(no)? ");

		scanf(" %c",&c);

		++i;
		if ( c == 'n' )
		{
			break;
		}
		else if ( c == 'y' )
		{
			printf("\n");
		}
	}

	printf("The class statistics:\n");
	printf("The average score on quiz1 is %.2f\n",avgQuiz1/i );
	printf("The average score on quiz2 is %.2f\n",avgQuiz2/i );
	printf("The average score on midterm is %.2f\n",avgMidterm/i );
	printf("The average score on final is %.2f\n",avgFinal/i );

	for (j = 0; j < i; ++j)
	{
		avgAll += s[j].score;
	}

	printf("The average score for the entire course is %.3f\n",avgAll/i );


	return 0;
}