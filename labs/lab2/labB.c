/*
 * Name: Bruce Cosgrove
 * Explanation:
 * I'm going to start with the easiest one first, 100, since all of its casts are still 100. There are two
 * reasons for this. The first is that 100 is positive, so casts to unsigned types won't have any effect.
 * There is a catch to that, but it is not applied here because 100 only needs 7 bits to represent. That
 * representation being 0b1100100, however because it's an int, it has 25 (32 - 7) leading zeros. When
 * casting 100 to a char, all of its 7 bits fit. Since a char is 8 bits, its representation is
 * 0b01100100. Since the sign bit is reset, both char and unsigned char will print the same value. Casting
 * to types with more bits literally just adds more leading zeros, so the value isn't changed.
 * 
 * Now for -100, and why there are large numbers. The answer to that is simple, when two's complementing 100
 * to get -100, 2^8 - 100, 2^32 - 100 and 2^64 - 100 are the results for char, int and long, respectively.
 * Of course, they would be interpreted differently for signed vs unsigned types.
 * 
 * As for 1000, since its positive, only casting to types with less bits than an int will have an effect.
 * This time, it takes more than 8 bits to represent, in this case 10 bits: 0b1111101000, so when casting
 * to a char, either signed or unsigned, the two most significant bits will be chopped off. The resulting
 * value will be 0b11101000; since the sign bit is set, casting to a signed char will result in a negative
 * value.
 * 
 * Finally -1000, since it's negative, casting to unsigned types with at least the same number of bits as
 * it will result in a big number; casting to signed types with more bits will not alter the value, as per
 * usual. The interesting part is casting to types with less bits. The two's complement of -1000 is
 * 0b0000011000, which actually can very easily fit into 8 bits (ignoring the leading zeros of course).
 * Since the sign bit is reset, both char and unsigned char will print the same value.
 */ 

// Again, unused includes.
#include <stdio.h>

void typecast(int a)
{
	unsigned int b = (unsigned int) a;
	unsigned char c = (unsigned char) a;
	char d = (char) a;
	unsigned long e = (unsigned long) a;
	long f = (long) a;
	
	printf(" %d: \n", a);
	printf(" ->unsigned int: %u\n", b);
	printf(" ->unsigned char (as decimal) %u\n", c);
	printf(" ->char (as decimal) %d\n", d);
	printf(" ->unsigned long: %lu\n", e);
	printf(" ->long: %ld\n", f);
}

// I applied the same whitespace edits to here as well.
int main()
{
	int num = 0;
	printf("Enter an integer: ");
	scanf("%d", &num);
	typecast(num);
	
	return 0;
}
