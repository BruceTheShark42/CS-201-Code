#include <stdio.h>


void one()
{
    int x = 5;
}

int two(short x)
{  
	short y = 10;
    return x - y;
}

int three(char x, long y)
{
	char a = 1;
    int z = 11;
    return a*x + y + z;
}

int four(int x,char y,long z,int w)
{
   return x + y + z + w;
}

