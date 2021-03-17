/*
 * Name: Bruce Cosgrove
 * 
 * I made the same whitespace edits as usual.
 */

// Thank you for not including any unused files
#include <stdlib.h> // for rand and srand
#include <string.h> // for strlen
#include <stdio.h>  // for printf
#include <time.h>   // for time

// PLEASE DON'T CHANGE THIS DEFINE!
#define NUMOFLINES 3000

int countAllVowels(char** lines)
{
	// What's the truth behind declaring all variables
	// at the beginning of the function scope? They're
	// all on the stack, so there shouldn't really be
	// that much of a performance difference.
	int i;
	int j;
	int count = 0;
	int length;
	char* line;
	char letter;
	for (i = 0; i < NUMOFLINES; i++)
	{
		line = lines[i];
		length = strlen(line);
		for (j = 0; j < length; j++)
		{
			letter = line[j];
			if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
				count++;
		}
	}
	return count;
}

void printLines(char** lines)
{
	for (int i = 0; i < NUMOFLINES; i++)
		printf("%s\n", lines[i]);
}

// PLEASE DON'T CHANGE THIS FUNCTION!
void createLines(char** lines)
{
	for (int i = 0; i < NUMOFLINES; i++)
	{
		int size = (rand() % 10000) + 1;
		lines[i] = (char*)malloc(sizeof(char) * size + 1);
		for (int j = 0; j < size; j++)
		{
			char letter = (char)(rand() % 26) + 97;
			lines[i][j] = letter;
		}
		lines[i][size]='\0';
	}
}

// Good practice...
void destroyLines(char** lines)
{
	for (int i = 0; i < NUMOFLINES; i++)
		free(lines[i]);
}

int main()
{
	char* lines[NUMOFLINES];
	
	srand((unsigned int)time(NULL));
	
	createLines(lines);
	//printLines(lines);
	int count = countAllVowels(lines);
	destroyLines(lines);
	printf("Vowel count: %d\n", count);
	
	return 0;
}
