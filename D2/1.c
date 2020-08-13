#include <stdio.h>
#include <time.h>
#include <math.h>

void method1(long n){
	int prime = 1;
	for(long i=2; i<n; i++){
		if(n%i == 0){
			prime = 0;
			break;
		}
	}
	if(prime == 1){
		printf("%ld is prime\n", n);
	}
	else{
		printf("%ld is not prime\n", n);
	}
}

void method2(long n){
	int prime = 1;
	for(long i=2; i<n/2; i++){
		if(n%i == 0){
			prime = 0;
			break;
		}
	}
	if(prime == 1){
		printf("%ld is prime\n", n);
	}
	else{
		printf("%ld is not prime\n", n);
	}
}

void method3(long n){
	int prime = 1;
	for(long i=2; i<sqrt(n); i++){
		if(n%i == 0){
			prime = 0;
			break;
		}
	}
	if(prime == 1){
		printf("%ld is prime\n", n);
	}
	else{
		printf("%ld is not prime\n", n);
	}
}


void main(){
	long n;
	printf("Enter number: ");
	scanf("%ld", &n);

	clock_t etime;
	etime = clock();
	method1(n);
	etime = clock() - etime;
	printf("Time taken by First method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);

	etime = clock();
	method2(n);
	etime = clock() - etime;
	printf("Time taken by Second method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);

	etime = clock();
	method3(n);
	etime = clock() - etime;
	printf("Time taken by Third method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);
}