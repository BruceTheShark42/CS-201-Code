/*
 * Name: Bruce Cosgrove
 */ 

#include <stdio.h>
#include <math.h>

// With C++ these could more easily, and safer, be done with unions.
//unsigned int getSign       (float number) { return ((*(unsigned int*)&number) & 0x80000000) >> 31; } // not used
unsigned int getMantissa   (float number) { return ((*(unsigned int*)&number) & 0x7f800000) >> 23; }
unsigned int getSignificand(float number) { return ((*(unsigned int*)&number) & 0x007fffff) >>  0; }

// If 0, number is even, otherwise, number is odd
int getOnesPlaceBit(float number)
{
	// If number is exactly 1.0f, the significand will be 0, and such would be treated as an even number.
	return number == 1.0f ? 1 : getSignificand(number) & (1 << (23 - (getMantissa(number) - 127)));
}

float roundEven(float number)
{
	// Exactly one of a or b is gaurenteed to be even unless the absolute
	// value of number is at least 2^24, in which case they are both even
	// because of rounding errors, so it doesn't matter.
	float a = floor(number);
	float b = floor(number + 1.0f);
	return getOnesPlaceBit(a) != 0 ? b : a;
}

float roundMinusInf(float number)
{
	return floor(number);
}

float roundPlusInf(float number)
{
	return floor(number + 1.0f);
}

float roundZero(float number)
{
	return (number < 0.0f ? -1.0f : 1.0f) * floor(fabs(number));
}

int main()
{
	float number = 0.0f;
	printf("Enter float number: ");
	scanf("%f", &number);
	
	float even = roundEven(number);
	float minus = roundMinusInf(number);
	float plus = roundPlusInf(number);
	float zero = roundZero(number);
	
	printf("Round to nearest even: %f\n", even);
	printf("Round to minus infinity: %f\n", minus);
	printf("Round to plus infinity: %f\n", plus);
	printf("Round toward zero: %f\n", zero);
	
	return 0;
}
