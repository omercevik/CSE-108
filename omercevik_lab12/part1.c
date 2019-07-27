#include <stdio.h>
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

int main()
{
	int size = 0;

	printf("Enter number of students: ");
	scanf("%d",&size);

	struct Student* s = (struct Student*)calloc(size,sizeof(struct Student));

	free(s);

	return 0;
}