#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int childCount = 4;
	
	for (int i = 0; i < childCount; i++)
	{
		if (fork() == 0)
		{
			int cpid = getpid();
			srand((unsigned int)(time(NULL) * cpid * (i + 1))); // I think multiplying by cpid is better than by i.
			int roll1 = rand() % 6 + 1;
			int roll2 = rand() % 6 + 1;
			printf("child: cpid=%d, roll1=%d, roll2=%d\n", cpid, roll1, roll2);
			return roll1 + roll2;
		}
	}
	
	// I originally had this in the first loop, but that made
	// it practically 100% of the time, each child would finish
	// in order. I like chaos, so that had to go.
	for (int i = 0; i < childCount; i++)
	{
		int status;
		int cpid = wait(&status);
		int sum = WEXITSTATUS(status);
		
		const char* state;
		switch (sum)
		{
			case 7:
			case 11:
				state = "won";
				break;
			case 2:
			case 3:
			case 12:
				state = "lost";
				break;
			default:
				state = "draw";
		}
		
		printf("parent: cpid=%d, sum=%d, state=%s\n", cpid, sum, state);
	}
	
	return 0;
}
