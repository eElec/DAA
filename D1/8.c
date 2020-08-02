#include <stdio.h>

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("\nOriginal Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	int prod = 1;
	for(int i=0; i<n; i++){
		prod *= arr[i];
	}

	for(int i=0; i<n; i++){
		arr[i] = prod / arr[i];
	}

	printf("\nNew Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}