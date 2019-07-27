#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_word(char* fname, char* wsrc, char* wdest);

int main(int argc, char const *argv[])
{
	char src[1024], dest[1024];

	printf("Enter dest word: ");
	scanf("%s",dest);
	replace_word("data.txt",src,dest);

	printf("SRC = %s, DEST = %s\n",src,dest);
	return 0;
}

void replace_word(char* fname, char* wsrc, char* wdest)
{
	int i = 0, wsrcLength = 0, wdestLength = 0;
	char temp[1024];
	char str[1024];

	FILE* fp = fopen(fname,"r+");

	if ( fp == NULL )
	{
		printf("File can not open.\n");
		return;
	}

	while ( fscanf(fp,"%c",&wsrc[i]) == 1 )
	{
		++i;
	}
	wsrc[i] = '\0';
	wsrcLength = i;
	printf("Change it: ");
	scanf(" %s",str);

	for (size_t i = 0; i < wsrcLength; i++)
	{
			if ( strncmp(&wsrc[i],wdest,strlen(wdest)) == 0 )
			{
					strcpy(temp,&wsrc[i+strlen(wdest)]);
					strcpy(&wsrc[i],str);
					strcpy(&wsrc[strlen(str)+i],temp);
			}
	}
	fseek(fp,0L,SEEK_SET);
	fprintf(fp, "%s",wsrc );
	fclose(fp);
}
