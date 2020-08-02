#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	long int arr[n];
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("\nOriginal Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%ld ", arr[i]);
	}
	for(int i=1; i<n; i+=2){
		swap(&arr[i-1], &arr[i]);
	}

	printf("\nSwapped Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%ld ", arr[i]);
	}
}