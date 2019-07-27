#include <stdio.h>
#include <stdlib.h>

struct customer
{
	char firstName[50];
	char lastName[50];
	int workYear;
	int salary;
	int accountNumber;
};

void fill(struct customer* st, size_t size, int count);

int main()
{
	int count = 0;
	size_t size = sizeof(struct customer);
	struct customer* st = NULL; 

	printf("Enter count: ");
	scanf("%d",&count);

	fill(st,size,count);
	
	return 0;
}

void fill(struct customer* st, size_t size, int count)
{
	FILE *fp = fopen("data.bin","wb+");
	int i = 0;

	if ( fp == NULL )
	{
		printf("File can not openned.\n");
		return;
	}

	st = (struct customer*)malloc(size*count);

	for (i = 0; i < count; ++i)
	{
		printf("First Name: ");
		scanf("%s",st[i].firstName);
		printf("Last Name: ");
		scanf("%s",st[i].lastName);
		printf("Acct Num: ");
		scanf("%d",&st[i].accountNumber);
		printf("Work Year: ");
		scanf("%d",&st[i].workYear);
		printf("Payment: ");
		scanf("%d",&st[i].salary);
	}

	fwrite(st,size,count,fp);
}