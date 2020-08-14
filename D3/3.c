#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Square root using Babylonian Method
float udSqrt(float n){
	float err = 0.000001;
	float x = n;
	float y = 1;

	while((x - y) > err){
		x = (x+y)/2;
		y = n/x;
	}
	return x;
}

int main(){
	float n;
	printf("Enter a number: ");
	scanf("%f", &n);

	printf("Approximate sqrt(%f): %f\n", n, udSqrt(n));
}