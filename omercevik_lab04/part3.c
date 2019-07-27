#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(int a);

int main()
{
	int random = 0, count = 0, player = 0, num = 5;

	srand(time(NULL));

	random = rand()%10;

	if ( random < 5 )
	{
		random += 5;
	}

	do{
		++count;
		printf("Trial %d - Enter throwing distance:",count);
		scanf("%d",&player);

		if ( player == random )
		{
			++num;

			draw(num);

			printf("\nYou hit the target!\n\n");

			printf("Target distance is %d.\n",random);
			break;
		}
		else
		{
			++num;

			draw(num);

			printf("\nYou could not hit the target!\n\n");
		}
		
	}while(1);
	
	return 0;
}

void draw(int a)
{
	int i = 0, j = 0, b = a/2, k = 0, t = a/2;

	for (i = 0; i < a/2-1; ++i)
	{
		for (j = b-2; j > 0; --j)
		{
			printf(" ");
		}
		--b;
		printf("/");

		for (k = 0; k < t-2; ++k)
		{
			printf(" ");
		}
		++t;
		printf("\\\n");
	}
}