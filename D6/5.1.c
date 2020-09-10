//Write a program to find the kth minimum and maximum element in Heap.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int arr[], int n, int pos){
	if(pos >= (n/2)){
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

void buildMaxHeap(int arr[], int n){
	for(int i=(n-1)/2; i>=0; i--){
		maxHeapify(arr, n, i);
	}
}

int extractMax(int arr[], int *n){
	*n = *n - 1;
	int max = arr[0];
	arr[0] = arr[*n];
	buildMaxHeap(arr, *n);
	return max;
}

int extractKMax(int arr[], int n, int k){
	int x = n;
	int copy[x];
	for(int i=0; i<x; i++){
		copy[i] = arr[i];
	}

	int KMax;
	for(int i=0; i<k && i<n; i++){
		KMax = extractMax(copy, &x);
	}

	return KMax;
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

	buildMaxHeap(arr, n);

	displayHeap(arr, n);

	int k;
	printf("Enter K: ");
	scanf("%d", &k);
	printf("Kth Max: %d\n", extractKMax(arr, n, k));
	printf("Kth Min: %d\n", extractKMax(arr, n, n-k+1));
}