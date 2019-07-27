#include <stdio.h>
#include <time.h>
#include <stdlib.h>

union StudentIdentifier
{
	char StudentNumber[11];
	long int SocialNumber;
};

struct Student
{
	union StudentIdentifier SI;
	char name[10];
	char surname[10];
	int mid1;
	int mid2;
	int final;
	int IdType;
	int Grade;
};

void create(struct Student *student);

int main()
{
	int size = 0, i = 0;

	srand(time(NULL));

	printf("Enter number of students: ");
	scanf("%d",&size);

	struct Student* s = (struct Student*)calloc(size,sizeof(struct Student));

	for (i = 0; i < size; ++i)
	{
		create(&s[i]);
	}

	free(s);

	return 0;
}

void create(struct Student *student)
{
	int no = 0;
	char *department = "2018-CS-";

	printf("Enter name: ");
	scanf("%s",student->name);
	printf("Enter surname: ");
	scanf("%s",student->surname);
	printf("Enter 1 or 0 to create SocialNumber (1) or StudentNumber (0) : ");
	scanf("%d",&student->IdType);

	if ( student->IdType == 0 )
	{
		printf("Enter Student Number No: ");
		scanf("%d",&no);

		if ( no > 10 && no < 100 )
		{
			sprintf(student->SI.StudentNumber,"%s0%d",department,no);
		}
		else if ( no < 10 )
		{
			sprintf(student->SI.StudentNumber,"%s00%d",department,no);
		}
		else if ( no > 99 )
		{
			sprintf(student->SI.StudentNumber,"%s%d",department,no);
		}
		printf("%s\n",student->SI.StudentNumber );
		
	}
	else
	{
		printf("Enter Social Number: ");
		scanf("%ld",&(student->SI.SocialNumber));
	}

	student->mid1 = rand()%100;
	student->mid2 = rand()%100;
	student->final = rand()%100;
}