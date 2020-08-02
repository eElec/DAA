#include <stdio.h>
#include <stdlib.h>

void main(){
	int n=0;
	printf("Enter size of array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		arr[i] = rand()%10 + 10;
	}

	int min = arr[0];
	int max = arr[0];

	for(int i=0; i<n ;i++){
		if(min > arr[i]){
			min = arr[i];
		}
		if(max < arr[i]){
			max = arr[i];
		}
	}
	printf("\nOriginal array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\nMin: %d\nMax: %d", min, max);
}