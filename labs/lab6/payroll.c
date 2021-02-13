/*
 * Name: Bruce Cosgrove
 */ 

#include <stdio.h>

/*
 * Part B: 10 points
 * See instructions on how to do this part.
 * See the website: http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#s4
 * for information on how to write gcc inline assembly.
 */
int regular_pay_asm(int payRate, int hours)
{
	// Remember to put any register names you are directly using in the clobber list.
	// gpay - %0  hours - %1  payrate - %2
	int gpay = 0;
	asm(   "cmpl	$40,%1\n"
		"	jle	lbl%=\n"
		"	movl	$40,%1\n"
		"lbl%=:\n"
		"	movl	%1,%%eax\n"
		"	imul	%2\n"
		"	movl	%%eax,%0"
	: "=r"(gpay)               /* outputs */
	: "r"(hours), "r"(payRate) /* inputs */
	: "eax", "edx"             /* clobbered registers */
	);
	
	// According to that website, listing the inputs, outputs, and clobbered registers is optional.
	// On top of that, using the inputs and outputs results in redundant assembly code even when optimizations are turned on.
	// When compiling this file with "gcc -O3 -S payroll.c" and removing the linker code to make it more readable:
	// regular_pay_asm:
	// #APP
	// # 18 "payroll.c" 1
	//	cmpl	$40,%esi
	//	jle	lbl5
	//	movl	$40,%esi
	//lbl5:
	//	movl	%esi,%eax
	//	imul	%edi
	//	movl	%eax,%esi  // here...
	//# 0 "" 2
	//#NO_APP
	//	movl	%esi, %eax // ...and here
	//	ret
	
	// I specifically had to add the "movl %eax,%esi" because I couldn't remove the "movl %esi,%eax"
	// Just some things I noticed.
	
	return gpay;
}


int regular_pay_c(int payRate, int hours)
{
	if (hours > 40)
		hours = 40;
	return hours * payRate;
}

int main()
{
	int pay_rate = 15;
	int hours = 30;
	
	printf("enter pay rate: ");
	scanf("%d",&pay_rate);
	printf("enter hours: ");
	scanf("%d",&hours);
	
	int rpay_c = regular_pay_c(pay_rate, hours);
	int rpay_asm = regular_pay_asm(pay_rate, hours);
	printf("regular pay (C) is: %d \n",rpay_c);
	printf("regular pay (asm) is: %d \n", rpay_asm);
	
	return 0;
}
