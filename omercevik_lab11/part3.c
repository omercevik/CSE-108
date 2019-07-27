#include <stdio.h>
#include <string.h>

union storeU
{
	int roll_no;
	int age;
	char name[100];
};

struct store
{
	int roll_no;
	int age;
	char name[100];
	union storeU u;
};

void printSameAges(struct store *st);
void printEvenRollNo(struct store *st);
void printAll(struct store *st,int roll);

int main()
{
	int i = 0,rol = 0;
	struct store student[5];

	for (i = 0; i < 5; ++i)
	{
		printf("%d) Enter name: ", i+1);
		scanf("%s",student[i].name);
		printf("%d) Enter age 11-14 : ", i+1);
		scanf("%d",&student[i].age);
		printf("%d) Enter roll no: ", i+1);
		scanf("%d",&student[i].roll_no);
	}

	printf("14 ages students are : \n");
	printSameAges(student);
	printf("Even roll no students are : \n");
	printEvenRollNo(student);
	printf("Enter roll name: ");
	scanf("%d",&rol);
	printf("Print all: \n");
	printAll(student,rol);

	return 0;
}

void printSameAges(struct store *st)
{
	int i = 0;

	for (i = 0; i < 5; ++i)
	{
		if ( st[i].age == 14 )
		{
			strcpy(st[i].u.name,st[i].name);
			printf("%s\n",st[i].u.name );
		}
	}
}

void printEvenRollNo(struct store *st)
{
	int i = 0;

	for (i = 0; i < 5; ++i)
	{
		if ( st[i].roll_no %2 == 0 )
		{
			strcpy(st[i].u.name,st[i].name);
			printf("%s\n",st[i].u.name );
		}
	}
}

void printAll(struct store *st, int roll)
{
	int i = 0;

	for (i = 0; i < 5; ++i)
	{
		if ( roll == st[i].roll_no )
		{
			printf("Name: %s\n", st[i].name);
			printf("Age : %d\n", st[i].age);
			printf("Roll no: %d\n", st[i].roll_no);
		}
	}
}