#include <stdio.h>
#include <time.h>
#include <math.h>
struct factors{
	int size;
	int factor[100];
	int exponent[100]; // number of times
};

int Euclid(int a, int b) 
{ 
    if (a == 0){
        printf("GCD: %d\n", b); 
		return b;
	}
    return Euclid(b % a, a); 
} 

void integerChecking(int a, int b){
	int t = (a < b)? a : b;
	while(t > 0){
		if( a%t==0 && b%t==0){
			printf("GCD: %d\n", t);
			return;
		}
		t--;
	}
}

void gcdFactor(int a, int b){
	if(a>b)
    	gcdFactor(b,a);
    int gcd=1;
    for(int i=2;i<=a;i++)
    {
        while(a%i==0 && b%i==0)
        {
			gcd = gcd * i;
			b = b / i;
			a = a / i;
			if (a == 0 || b == 0){
				printf("GCD: %d\n", gcd);
				return;
			}
		}
    }
	printf("GCD: %d\n", gcd);
}

void main(){
	clock_t etime;
	etime = clock();
	Euclid(31415, 14142);
	etime = clock() - etime;
	printf("Time taken by Euclid method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);

	etime = clock();
	integerChecking(31415, 14142);
	etime = clock() - etime;
	printf("Time taken by integerChecking method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);

	etime = clock();
	gcdFactor(31415, 14142);
	etime = clock() - etime;
	printf("Time taken by Middle School method: %f\n", (double)etime / (double)CLOCKS_PER_SEC);
}