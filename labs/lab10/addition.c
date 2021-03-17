#include <stdlib.h> // for rand and srand
#include <stdio.h>  // for printf
#include <time.h>   // for time

// PLEASE DON'T CHANGE THESE DEFINES!
#define ROWS 2000
#define COLS 2000

long addition(short table[][COLS])
{
	short* tableStart = *table;
	int size = ROWS * COLS;
	long sum = 0;
	for (int i = 0; i < size; i++)
		sum += tableStart[i];
	
	return sum;
}

void printTable(short table[][COLS])
{
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
			printf("%d ", table[j][i]);
		printf("\n");
	}
}

// PLEASE DON'T CHANGE THIS FUNCTION!
void createTable(short table[][COLS])
{
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			short number = (rand() % 10) + 1;
			table[j][i] = number;
		}
	}
}

int main()
{
	// This is a lot of memory on the stack
	// 8MB assuming no padding.
	short table[ROWS][COLS];
	
	srand((unsigned int)time(NULL));
	
	createTable(table);
	//printTable(table);
	long sum = 0;
	for (int i = 0; i < 1000; i++)
	    sum = addition(table);
	printf("Sum: %ld\n", sum);
	
	return 0;
}
