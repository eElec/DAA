#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter Array Elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	int SMax = INT_MIN;
	int S = 0;
	int x=0, y=0;
	for(int i=0; i<n; i++){
		S = 0;
		for(int j=i; j<n; j++){
			S+=arr[j];
			if(S > SMax){
				SMax = S;
				x = i;
				y = j;				
			}
		}
	}

	printf("\nMaximum Sum: S(%d, %d) = %d\n", x, y, SMax);
}