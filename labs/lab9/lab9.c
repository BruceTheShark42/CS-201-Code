#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile int damageDealt = 0;
volatile int otherDead = 0;

void signalHandler(int signum)
{
	if (signum == SIGALRM)
		damageDealt = rand() % 50 + 1; // 1 - 50
	else
		otherDead = 1;
}

void attack(int pid)
{
	kill(pid, SIGALRM);
	sleep(rand() % 3 + 1);
}

int main()
{
	// Create the mask ahead of time
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGALRM);
	//sigaddset(&mask, SIGCHLD); // Not required
	
	// Setup the signal handler
	signal(SIGALRM, signalHandler);
	signal(SIGCHLD, signalHandler);
	
	// Stores the process name so I don't have to check it every time I print
	const char* processName;
	
	// Get the pid to the process that the current process is "attacking"
	int otherPID = fork();
	int pid = getpid();
	srand((unsigned int)(time(NULL) * pid));
	if (otherPID > 0)
		processName = "parent";
	else if (otherPID == 0)
	{
		processName = "child ";
		otherPID = getppid();
	}
	
	const int maxDamage = 250;
	const int maxHits = 10;
	int damage = 0;
	int hits = 0;
	
	// Initial attack to start things off
	attack(otherPID);
	
	while (damage < maxDamage && hits < maxHits && !otherDead)
	{
		if (damageDealt != 0)
		{
			sigprocmask(SIG_BLOCK, &mask, NULL);
			
			hits++;
			damage += damageDealt;
			printf("%s %5d was hit for %2d damage. Total damage is %3d.\n", processName, pid, damageDealt, damage);
			damageDealt = 0;
			attack(otherPID);
			
			sigprocmask(SIG_UNBLOCK, &mask, NULL);
		}
	}
	
	// print win/loss message
	printf("%s %d has %s.\n", processName, pid, damage < maxDamage ? "survived" : "died");
	
	if (otherPID > 0)
	{
		// parent automatically receives SIGCHLD if child dies first
		kill(otherPID, SIGCHLD);
		wait(NULL);
	}
	
	return 0;
}
