/*
 * Name: Bruce Cosgrove
 * Example 1 was not working before I fixed the equals function
 * because of round off errors when converting 100.6f to binary
 * and when subtracting 0.1f. Since the == operator checks for
 * exact equality, meaning every bit is the same, even if one
 * bit is off, they are considered not equal.
 */ 

// ...
#include <stdio.h>
#include <math.h>

int equals(float a, float b)
{
	return fabs(a - b) < 0.0001f ? 1 : 0;
}

void example1()
{
	
	float a = 100.6f;
	float b = 100.0f;
	
	for (int i = 0; i < 6; i++)
		a -= 0.1f;
	
	printf("Example 1: these should equal each other\n");
	printf("%f and %f are%s equal.\n", a, b, equals(a, b) ? "" : " NOT");
}

void example2()
{
	float a = 100.006f;
	float b = 100.0f;
	
	for(int i = 0; i < 7; i++)
		a -= 0.001f;
	
	printf("Example 2: these should NOT equal each other\n");
	printf("%f and %f are%s equal.\n", a, b, equals(a, b) ? "" : " NOT");
}

int main()
{
	example1();
	example2();
	return 0;
}
