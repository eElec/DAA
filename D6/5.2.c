/*
 * HE5.2 Write a program to delete kth indexed element in
 * Min heap and Max heap. HE5.3 Write an algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int arr[], int n, int pos){
	if(pos >= (n-1/2)){
		return;	
	}
	int l = pos*2 + 1;
	int r = pos*2 + 2;
	int largest = pos;
	if(arr[largest] < arr[l] && l < n){
		largest = l;
	}
	if(arr[largest] < arr[r] && r < n){
		largest = r;
	}

	if(largest != pos){
		swap(&arr[largest], &arr[pos]);
		maxHeapify(arr, n, largest);
	}
}

void minHeapify(int arr[], int n, int pos){
	int l = pos*2 + 1;
	int r = pos*2 + 2;
	int smallest = pos;
	if(arr[smallest] > arr[l] && l < n){
		smallest = l;
	}
	if(arr[smallest] > arr[r] && r < n){
		smallest = r;
	}

	if(smallest != pos){
		swap(&arr[smallest], &arr[pos]);
		minHeapify(arr, n, smallest);
	}
}

void displayHeap(int arr[], int n){
	printf("\nRoot\tLeft\tRight\n");
	for(int i=0; i<n/2; i++){
		int l = i*2+1;
		int r = i*2+2;
		if(l < n && r < n)
			printf("%d (%d)\t%d (%d)\t%d (%d)\n", arr[i], i, arr[l], l, arr[r], r);
		else if(l < n)
			printf("%d (%d)\t%d (%d)\n", arr[i], i, arr[l], l);
	}
}

void DeletionFromMaxHeap(int arr[], int n, int k){
	//Create a Duplicate Array
	int maxHeap[n];
	for(int i=0; i<n; i++){
		maxHeap[i] = arr[i];
	}

	for(int i=(n-1)/2; i>=0; i--){
		maxHeapify(maxHeap, n, i);
	}

	printf("MaxHeap: ");
	// for(int i=0; i<n; i++)
	// 	printf("%d ", maxHeap[i]);
	// printf("\n");
	displayHeap(maxHeap, n);

	// Removing Kth Element
	n--;
	maxHeap[k] = maxHeap[n];
	for(int i=(n-1)/2; i>=0; i--){
		maxHeapify(maxHeap, n, i);
	}

	printf("\nAfter Deleting Kth Element: ");
	displayHeap(maxHeap, n);
}

void DeletionFromMinHeap(int arr[], int n, int k){
	//Create a Duplicate Array
	int minHeap[n];
	for(int i=0; i<n; i++){
		minHeap[i] = arr[i];
	}

	for(int i=(n-1)/2; i>=0; i--){
		minHeapify(minHeap, n, i);
	}

	printf("MinHeap: ");
	displayHeap(minHeap, n);

	// Removing Kth Element
	n--;
	minHeap[k] = minHeap[n];
	for(int i=(n-1)/2; i>=0; i--){
		minHeapify(minHeap, n, i);
	}

	printf("\nAfter Deleting Kth Element: ");
	displayHeap(minHeap, n);
}


void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	printf("Enter Elements: ");
	// srand(clock());
	int arr[n];
	for(int i=0; i<n; i++){
		// arr[i] = rand()%100;
		scanf("%d", &arr[i]);
	}
	// int arr[] = {9, 8, 6, 5, 2,1 };
	// int arr[] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
	// n = sizeof(arr)/sizeof(int);
	// for(int i=0; i<n; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");

	int k;
	printf("Enter K: ");
	scanf("%d", &k);

	printf("\n");
	DeletionFromMaxHeap(arr, n, k);
	printf("\n");
	DeletionFromMinHeap(arr, n, k);
}