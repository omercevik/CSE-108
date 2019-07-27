#include <stdio.h>

typedef enum { Monday = 0, Tuesday = 1, Wednesday = 2, Thursday = 3, Friday = 4, Saturday = 5, Sunday = 6  }days;

int min_day_to_reach(int cultural_point);
int any_activity_point(int day_count);

int main()
{
	min_day_to_reach(51);

	return 0;
}

int min_day_to_reach(int cultural_point)
{
	int mehmetCounter = 0, sumPoints = 0, temp = 0;

	sumPoints = cultural_point;
	temp = cultural_point;

	while( sumPoints > 0)
	{
		mehmetCounter += 5;

		if ( mehmetCounter%7 == 0 )
		{
			sumPoints -= 3;
		}
		else if ( mehmetCounter%10 == 0 )
		{
			sumPoints -= 2;
		}
		else if ( mehmetCounter%5 == 0 )
		{
			sumPoints -= 1;
		}
	}

	printf("Mehmet can obtain %d cultural points at least %d days.\n\n", temp, mehmetCounter );

	any_activity_point(mehmetCounter);

	return 1;
}

int any_activity_point(int day_count)
{
	int countMonth = 0, temp = 0, countYear = 0, thisYear = 2018, thisMonth = 3, thisDay = 30, tempDay = 0;
	tempDay = day_count;

	while( day_count > 0 )
	{
		day_count -= 30;
		++countMonth;
	}

	temp = countMonth;

	if ( temp/12 > 0 )
	{
		while( temp > 0 )
		{
			++countYear;
			temp -=12;
		}
		countMonth = temp;
	}
	else
	{
		printf("The date after %d day from is %d/0%d/%d, ", tempDay, thisDay+day_count, thisMonth+countMonth, thisYear+countYear);

		if ( day_count == Monday )
		{
			printf("Monday.\n");
		}
		else if ( day_count == Tuesday )
		{
			printf("Tuesday.\n");
		}
		else if ( day_count == Wednesday )
		{
			printf("Wednesday.\n");
		}
		else if ( day_count == Thursday )
		{
			printf("Thursday.\n");
		}
		else if ( day_count == Friday )
		{
			printf("Friday.\n");
		}
		else if ( day_count == Saturday )
		{
			printf("Saturday.\n");
		}
		else
		{
			printf("Sunday.\n");
		}
	}

	return 1;
}