#include <stdio.h>

int main()
{
	int number, position;
	printf("enter number: ");
	scanf("%d", &number);
	printf("enter position (0 to 31): ");
	scanf("%d", &position);
	printf("value is %d\n", position < 0 || position > 31 ? -1 : ((number & (1 << position)) != 0 ? 1 : 0));
	return 0;
}
