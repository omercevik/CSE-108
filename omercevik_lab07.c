#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{ up = 1, down = 2, left = 3, right = 4}direction;

void init_maze01(char maze1[][10], int size);
void show_maze(char maze[][10], int size);
void move(char maze[][10], int pos_x, int pos_y);
void init_maze02(char maze2[][10], int size);
int move_test(char maze[][10], int pos_x, int pos_y, int direction);

int main()
{
	char m1[10][10], m2[10][10];
	init_maze01(m1,8);
	init_maze02(m2,10);
	srand(time(NULL));

	show_maze(m1,8);	/* maze 1 random */
	printf("\n");
	move(m1,3,3);
	show_maze(m1,8);

	show_maze(m2,10);	/* maze 2 random */
	printf("\n");
	move(m2,1,1);
	show_maze(m2,10);

	init_maze02(m2,10);

	show_maze(m2,10);	/* maze 2 test 	*/
	printf("\n");
	move_test(m2,1,1,0);
	show_maze(m2,10);

	return 0;
}

int move_test(char maze[][10], int pos_x, int pos_y, int direction)
{
	int random = 0, i = 100, temp = 0;
	temp = pos_x;

	while( 0 < i )
	{
		printf("Please enter the direction: (1): Up  (2): Down  (3): Left  (4): Right  : ");
		scanf("%d",&direction);

		if ( direction == up )
		{
			if ( maze[pos_x-1][pos_y] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x-1;
				maze[pos_x][pos_y] = 'S';
				printf("Test succeeded!\n");
				break;
			}
			else if ( maze[pos_x-1][pos_y] == '*' )
			{
				printf("Test failed.\n");
				break;
			}
			else if ( maze[pos_x-1][pos_y] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x-1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( direction == down )
		{
			if ( maze[pos_x+1][pos_y] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x+1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x+1][pos_y] == '*' )
			{
				printf("Test failed.\n");
				break;
			}
			else if ( maze[pos_x+1][pos_y] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x+1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( direction == left )
		{
			if ( maze[pos_x][pos_y-1] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y-1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x][pos_y-1] == '*' )
			{
				printf("Test failed.\n");
				break;
			}
			else if ( maze[pos_x][pos_y-1] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y-1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( direction == right )
		{
			if ( maze[pos_x][pos_y+1] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y+1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x][pos_y+1] == '*' )
			{
				printf("Test failed.\n");
				break;
			}
			else if ( maze[pos_x][pos_y+1] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y+1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		if ( temp == 3 )
		{
			show_maze(maze,8);
		}
		else
		{
			show_maze(maze,10);
		}
		--i;
	}

	if ( i == 0 )
	{
		printf("Test failed!\n");
	}
}

void move(char maze[][10], int pos_x, int pos_y)
{
	int random = 0, i = 100, temp = 0;
	temp = pos_x;

	while( 0 < i )
	{
		random = rand()%5 +1 ;

		if ( random == up )
		{
			if ( maze[pos_x-1][pos_y] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x-1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x-1][pos_y] == '*' )
			{
				continue;
			}
			else if ( maze[pos_x-1][pos_y] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x-1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( random == down )
		{
			if ( maze[pos_x+1][pos_y] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x+1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x+1][pos_y] == '*' )
			{
				continue;
			}
			else if ( maze[pos_x+1][pos_y] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_x = pos_x+1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( random == left )
		{
			if ( maze[pos_x][pos_y-1] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y-1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x][pos_y-1] == '*' )
			{
				continue;
			}
			else if ( maze[pos_x][pos_y-1] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y-1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		else if ( random == right )
		{
			if ( maze[pos_x][pos_y+1] == 'F' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y+1;
				maze[pos_x][pos_y] = 'S';
				printf("Nothing like freedom!\n");
				break;
			}
			else if ( maze[pos_x][pos_y+1] == '*' )
			{
				continue;
			}
			else if ( maze[pos_x][pos_y+1] == ' ' )
			{
				maze[pos_x][pos_y] = ' ';
				pos_y = pos_y+1;
				maze[pos_x][pos_y] = 'S';
			}
		}
		if ( temp == 3 )
		{
			show_maze(maze,8);
		}
		else
		{
			show_maze(maze,10);
		}
		--i;
	}

	if ( i == 0 )
	{
		printf("Oh, trap!\n");
	}	
}

void show_maze(char maze[][10], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%c ",maze[i][j] );
		}
		printf("\n");
	}
}

void init_maze01(char maze1[][10], int size)
{
	int i = 0, j = 0;

	for (i = 0; i < size; ++i)
	{
		if ( i == 0 || size-i == 1 )
		{
			for (j = 0; j < size; ++j)
			{
				if ( j == 6 && i == 0 )
				{
					maze1[i][j] = 'F';
				}
				else
					maze1[i][j] = '*';
			}
		}
		else
		{
			for (j = 0; j < size; ++j)
			{
				if ( j == 0 || size-j == 1 )
				{
					maze1[i][j] = '*';
				}
				else if ( (j == 4) && (i == 1 || i == 2 || i == 3) )
				{
					maze1[i][j] = '*';
				}
				else if ( (j == 2) && (i == 2 || i == 3 || i == 4 || i == 5) )
				{
					maze1[i][j] = '*';
				}
				else if ( (j == 3) && (i == 3) )
				{
					maze1[i][j] = 'S';
				}
				else if ( (i == 4 || i == 5) && (j == 5) )
				{
					maze1[i][j] = '*';
				}
				else if ( (i == 5) && (j == 3) )
				{
					maze1[i][j] = '*';
				}
				else
				{
					maze1[i][j] = ' ';
				}
			}
		}
	}
}

void init_maze02(char maze2[][10], int size)
{
	int i = 0, j = 0;

	for (i = 0; i < size; ++i)
	{
		if ( i == 0 || size-i == 1 )
		{
			for (j = 0; j < size; ++j)
			{
				maze2[i][j] = '*';
			}
			j = 0;
		}
		else
		{
			for (j = 0; j < size; ++j)
			{
				if ( i == 1 && j == 1 )
				{
					maze2[i][j] = 'S';
				}
				else if ( j == 0 || size-j == 1 )
				{
					if ( j == size-1 && i == 6 )
					{
						maze2[i][j] = 'F';
					}
					else
						maze2[i][j] = '*';
				}
				else if ( (i == 1 || i == 2 || i == 4 || i == 5 || i == 6 || i == 7) && j == 2 )
				{
					maze2[i][j] = '*';
				}
				else if ( (i == 2 || i == 3 || i == 4 || i == 5) && j == 4 )
				{
					maze2[i][j] = '*';
				}
				else if ( (i == 7 || i == 8) && j == 3 )
				{
					maze2[i][j] = '*';
				}
				else if ( (i == 1 || i == 2 || i == 3 || i == 7) && j == 6 )
				{
					maze2[i][j] = '*';
				}
				else if ( (i == 5 || i == 6 || i == 7) && (j == 5 || j == 7) )
				{
					maze2[i][j] = '*';
				}
				else if ( i == 2 && j == 8 )
				{
					maze2[i][j] = '*';
				}
				else
				{
					maze2[i][j] = ' ';
				}
			}
		}
	}
}