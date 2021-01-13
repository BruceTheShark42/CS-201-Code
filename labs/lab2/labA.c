/*
 * Name: Bruce Cosgrove
 * Explanation:
 * 20 prints <= 100 because the representation for 20 as a signed int and an unsigned int are the same.
 * The same reasoning can be applied to all positive numbers, including 200. However since 200 is already
 * greater than 100, it prints that. The fiddly parts are comparing negative signed numbers to unsigned
 * numbers. The unsigned number acts as normal, however, the same is not true for the signed number. The
 * signed number is interpreted as an unsigned number, which is where the "weird" outputs come from. Those
 * outputs are due to the two's complement. To get the two's complement, just subtract the number that should
 * be negative from 2 to the power of however many bits in the type. In the case of -100, that would be
 * 2^32 - 100, which is most definetly greater than 100. No matter what the value, any negative number,
 * when interpreted as a signed number, will print > 100.
 */

// Why were there three includes that weren't used? That's just wasted compile time.
#include <stdio.h>

void compare(int a)
{
	// I prefer to be explicit. Like was commented, "unsigned" is just "unsigned int", so no functionality
	// changed.
	unsigned int b = 100;
	
	if(a <= b || (a & 0x80000000) != 0)
		printf("a (%d) <= b (%d)\n", a, b);
	else
		printf("a (%d) > b (%d)\n", a, b);
}

// Technically, I did change this, but ONLY whitespace. Eg: I changed "int num=0;" to "int num = 0;" and the
// return statement had spaces instead of tabs, so I changed that too. No functionality was altered whatsoever.
int main()
{
	int num = 0;
	printf("Enter an integer: ");
	scanf("%d", &num);
	compare(num);
	
	return 0;
}
