/*
 * Name: Bruce Cosgrove
 */ 

// And again, more unused includes... whyyyy??
#include <stdio.h>
#include <math.h>

int multiply(int a, int b)
{
	// I originally had this just be "while (b != 1)", but that led to an
	// infinite loop when entering the numbers 1 and 31 because the >>=
	// operator shifts all the bits to the right by one, but keeps the
	// most significant bit the same. So since the most significant bit
	// is set with those inputs, b would never equal one.
	while ((b & 1) != 1)
	{
		b >>= 1;
		a <<= 1;
	}
	return a;
}

// Even more whitespace changes.
int main()
{
	int num = 0;
	int e = 0;
	printf("Enter an integer: ");
	scanf("%d", &num);
	printf("Enter a power of 2 for the second number: ");
	scanf("%d", &e);
	int num2 = (int)pow(2, e);
	printf("the second number is: %d\n", num2);
	int prod = multiply(num, num2);
	printf("the product from return: %d\n", prod);
	int rprod = num * num2;
	printf("the product is: %d\n", rprod);
	
	return 0;
}
