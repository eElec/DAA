#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int elem, int l, int h){
	if(l > h){
		return -1;
	}
	else{
		int mid = (h+l)/2;
		if(arr[mid] == elem){
			return mid;
		}
		else if(arr[mid] > elem){
			return binarySearch(arr, elem, l, mid-1);
		}
		else{
			return binarySearch(arr, elem, mid+1, h);
		}
	}
}

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	int arr[n];
	srand(clock());
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

	//Sorting the array
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("Sorted Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int elem;
	printf("Enter Element to be searched: ");
	scanf("%d", &elem);

	time_t bst = clock();
	int pos = binarySearch(arr, elem, 0, n);
	bst = clock() - bst;

	if(pos!=-1)
		printf("Element %d is found at position %d\n", elem, pos+1);
	else
		printf("Element %d is not found in the array.\n", elem);

	printf("Time Taken: %f\n", (double)bst/(double)CLOCKS_PER_SEC);
}