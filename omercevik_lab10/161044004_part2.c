#include <stdio.h>

int count_of_vowels(char *text, char *vowels, int vowels_count);
int rec(char *tt, char v, int count);

int main()
{
	char *t = "This is an example. Try to get numbers of vowels that are in the sentence.";
	char *vowels = "aeiou";
	int count = 0;

	count = count_of_vowels(t,vowels,count);
	printf("Number of Vowels = %d\n",count );
	return 0;
}

int count_of_vowels(char *text, char *vowels, int vowels_count)
{
	if ( vowels == NULL )
	{
		return vowels_count;
	}
	else
	{	
		vowels_count = rec(text,vowels[0],vowels_count);

		return count_of_vowels(text,&vowels[1],vowels_count);
	}
}

int rec(char *tt, char v, int count)
{
	if ( tt == NULL )
	{
		return count;
	}
	else
	{
		if ( tt[0] == v )
		{
			return rec(&tt[1],v,count+1);
		}
		else
		{
			return rec(&tt[1],v,count);
		}
	}
}