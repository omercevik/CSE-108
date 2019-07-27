#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findingValue(int array[100], int sizeArray);

int main()
{
	int initalArray[100], inputArraySize = 100;

	srand(time(NULL));

	findingValue(initalArray,inputArraySize);
	
	return 0;
}

void findingValue(int array[100], int sizeArray)
{
	int i = 0, rangeOfRandom = 0, avr = 0, sum = 0, guess = 0;

	printf("Please enter range of random numbers 0-to: ");
	scanf("%d",&rangeOfRandom);
	printf("\n");

	for (i = 0; i < sizeArray; ++i)
	{
		array[i] = rand()%rangeOfRandom;
	}

	for (i = 0; i < sizeArray; ++i)
	{
		sum += array[i];
	}

	avr = sum/sizeArray;

	printf(" Average :: %d\n",avr );

	printf("You have 5 guess to find average of the list.\n\n");

	i = 5;

	while( i > 0 )
	{
		printf("Make your guess (%d left): ",i );

		scanf("%d",&guess);

		printf("\n");

		if ( guess == avr )
		{
			printf("Congratulations! You guessed well.\n");
			break;
		}
		else if ( guess > avr && ((avr-guess > 10) || (guess-avr > 10)) )
		{
			printf("Cold, you should decrease your guess!\n\n");
			--i;
		}
		else if ( guess < avr && ((avr-guess > 10) || (guess-avr > 10)) )
		{
			printf("Cold, you should increase your guess!\n\n");
			--i;
		}
		else if ( (avr-guess < 10) || (guess-avr < 10) )
		{
			printf("Hot, you almost find the average!\n\n");
			--i;
		}
	}

	if ( i == 0 )
	{
		printf("Sorry, you couldn't find the right value.\n");
	}
}