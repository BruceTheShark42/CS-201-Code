/*
 * Name: Bruce Cosgrove
 * Answers:
 * A: 16777216, or 2^24, is the last value they are equivalent.
 * B: The next value would be 16777217, or 2^24 + 1.
 * C and D:
 *  Last bits: 0 10010111 00000000000000000000000
 *   The sign bit is reset because 16777216 is positive.
 *   The mantissa is 24 + 127 = 151 = 0b10010111
 *   The significand is all zeros because 16777216 is exactly a power of two.
 *  Next bits: 0 10010111 00000000000000000000000
 *   The sign bit is reset because 16777217 is positive.
 *   The mantissa is 24 + 127 = 151 = 0b10010111
 *   The significand is all zeros because 16777217 would need a 24th bit to
 *    represent, however since only 23 are provided, it gets cut off as a
 *    rounding error. This rounding error is what causes the values to
 *    stop matching after some time.
 */

// Seriously, four unused includes...
#include <stdio.h>

void lastInt()
{
	float fi = 15000000.0f;
	unsigned int i = 15000000; 
	
	for (; i < 1e32; fi++, i++)
	{
		printf("%u -> %f\n", i, fi);
		if (i != (int)fi)
			break;
	}
}

int main()
{
	lastInt();
	return 0;
}
