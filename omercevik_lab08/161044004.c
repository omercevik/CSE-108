#include <stdio.h>


void pretty_print(int grid[][9]);
int is_valid_row(int grid[][9], int row);
int is_valid(int grid[][9]);
int is_valid_column(int grid[][9], int col);
int is_valid_block(int grid[][9], int r, int c);

void read_a_solution(int grid [][9], char * file_name);
void print_board(int grid[][9]);
void test_game(char * file_name);


int main() {
	test_game("game001.txt");
	test_game("game002.txt");
}


void pretty_print(int grid[][9]) {
	
	
}


int is_valid_row(int grid[][9], int row) {
	int i = 0, j = 0, digits[10], flag = 1, zero = 0;

	for (i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	for (i = 1; i < 10; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			if ( i == grid[row][j] )
			{
				++digits[i];
			}
			else if ( digits[i] == 0 )
			{
				++zero;
			}
		}
	}

	for (i = 1; i < 10; ++i)
	{
		if ( digits[i] > 1 || zero > 1 )
		{
			flag = 0;
			break;
		}
	}

	if ( flag == 0 )
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}


int is_valid_column(int grid[][9], int col) {
	int i = 0, j = 0, digits[10], flag = 1, zero = 0;

	for (i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	for (i = 1; i < 10; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			if ( i == grid[j][col] )
			{
				++digits[i];
			}
			else if ( digits[i] == 0 )
			{
				++zero;
			}
		}
	}

	for (i = 1; i < 10; ++i)
	{
		if ( digits[i] > 1 || zero > 1 )
		{
			flag = 0;
			break;
		}
	}

	if ( flag == 0 )
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}


int is_valid_block(int grid[][9], int r, int c) {
	int i = 0, j = 0, k = 0, digits[10], flag = 1, t1 = 0, t2 = 0, zero = 0;

	for (i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	if ( r == 0 )
	{
		t1 = 0;
	}
	else if ( r == 1 )
	{
		t1 = 3;
	}
	else if ( r == 2 )
	{
		t1 = 6;
	}

	if ( c == 0 )
	{
		t2 = 0;
	}
	else if ( c == 1 )
	{
		t2 = 3;
	}
	else if ( c == 2 )
	{
		t2 = 6;
	}

	for (i = 1; i < 10; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			for (k = 0; k < 3; ++k)
			{
				if ( i == grid[j+t1][k+t2] )
				{
					++digits[i];
				}
				else if ( digits[i] == 0 )
				{
					++zero;
				}
			}
		}
	}

	for (i = 1; i < 10; ++i)
	{
		if ( digits[i] > 1 || zero > 1 )
		{
			flag = 0;
			break;
		}
	}

	if ( flag == 0 )
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}


int is_valid(int grid[][9]) {
	
	int counter1 = 0, counter2 = 0, counter3 = 0, i = 0, j = 0;


	for (j = 0; j < 9; ++j)
	{
		if ( is_valid_row(grid,j) == 1 )
		{
			++counter1;
		}
	}

	for (i = 0; i < 9; ++i)
	{
		if ( is_valid_column(grid,i) == 1 )
		{
			++counter3;
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if ( is_valid_block(grid,j,i) == 1 )
			{
				++counter2;
			}
		}
	}
	if ( counter1 == 9 && counter2 == 9 && counter3 == 9 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void read_a_solution(int grid [][9], char * file_name) {
	FILE * fin;
    int i, j;

	fin = fopen(file_name, "rt");
	if (fin==NULL) {
		printf("Cannot open file %s for reading the game...\n", file_name);
	}
	else {
	    for (i = 0; i < 9; i++)
	        for (j = 0; j < 9; j++)
	            fscanf(fin, "%d", &grid[i][j]);
	}
}


void print_board(int grid[][9]) {
    int i, j;

	for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}


void test_game(char * file_name) {
    int grid[9][9];
	printf("Testing game in %s.............................\n", file_name);
    read_a_solution(grid, file_name);
	pretty_print(grid);
	print_board(grid);
    if (is_valid(grid))
       printf("Valid solution\n");
    else
		printf("Invalid solution\n");
}
