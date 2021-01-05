#include <stdio.h>

#define SIZE 100

struct Employee
{
	char lastName[SIZE];
	float payRate; // A double is not needed at all
};

void printPayroll(struct Employee* list, int count)
{
	printf("*** PAYROLL ***\n");
	for (int i = 0; i < count; i++)
		printf("Last Name: %s\nPay Rate: %.2f\n", list[i].lastName, list[i].payRate);
}

int createPayroll(struct Employee* list)
{
	int count = 0;
	
	do
	{
		printf("How many employees? ");
		scanf("%d", &count);
		if (count > SIZE)
			printf("Too many employees. Please enter a number under %d.\n", SIZE);
	}
	while (count > SIZE);
	
	for (int i = 0; i < count; i++)
	{
		printf("For employee %d.\nLast name: ", i + 1);
		scanf("%s", list[i].lastName);
		printf("Pay rate: ");
		scanf("%f", &list[i].payRate);
	}
}

int main()
{
	struct Employee list[SIZE];
	int count = createPayroll(list);
	printPayroll(list, count);
	return 0;
}
