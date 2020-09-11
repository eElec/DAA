/* LE7.1 Write a program to compare the time complexity of Fibonacci series
 * in divide and conquer and dynamic programming.Display both time
 * complexities with conclusion.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define NIL -1
unsigned long int LOOKUP[MAX];


unsigned long int fibDynamic(unsigned long int n){
	if(LOOKUP[n] == NIL){
		if(n <= 1){
			LOOKUP[n] = n;
		}
		else{
			LOOKUP[n] = fibDynamic(n-1) + fibDynamic(n-2);
		}
	}
	return LOOKUP[n];
}

unsigned long int fibDivConquer(unsigned long int i){
	if(i <= 1){
		return i;
	}
	return fibDivConquer(i-1) + fibDivConquer(i-2);
}

void main(){
	printf("Calculating Fib(40) using Divide and Conquer...\n");
	clock_t run = clock();
	fibDivConquer(40);
	run = clock() - run;
	printf("Run Time: %f\n", (float)run/CLOCKS_PER_SEC);

	for(int i=0; i<MAX; i++){
		LOOKUP[i] = NIL;
	}
	printf("\nCalculating Fib(40) using Dynamic Programming...\n");
	run = clock();
	fibDynamic(40);
	run = clock() - run;
	printf("Run Time: %f\n", (float)run/CLOCKS_PER_SEC);
}