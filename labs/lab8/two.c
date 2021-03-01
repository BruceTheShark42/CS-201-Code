#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

void doWork()
{
	int size = 10000;
	int x;
	int n = rand() % 5;
	sleep(n);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			x = i * j;  
			x = x;
		}
	}
}

int main()
{
	int pid = fork();
	
	if (pid == 0)
	{
		srand((unsigned int)time(NULL));
		doWork();
		printf("red\n");
		doWork();
		printf("yellow\n");
	}
	else
	{
		srand((unsigned int)time(NULL) * 103);
		doWork();
		printf("blue\n");
		doWork();
		printf("green\n");
		wait(NULL);
	}
	
	return 0;
}
