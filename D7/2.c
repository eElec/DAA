/* LE7.2 Write an algorithm MAX-HEAP-CHANGE-KEY(A, n, i, key), to
 * re-build a n-element max-heap A, after the value at node with index i has
 * been changed to a new value key. Illustrate the operation of
 * MAX-HEAP-CHANGE-KEY(A, 12, 2, 2) on the heap A={15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1}.
 * Assume root is at index 1.
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

void MaxHeapChangeKey(int arr[], int n, int pos, int key){
	pos = pos - 1;
	if(pos > n){
		return;
	}
	arr[pos] = key;
	buildMaxHeap(arr, n);
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
	int arr[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
	int n = sizeof(arr)/sizeof(int);

	displayHeap(arr, n);

	MaxHeapChangeKey(arr, n, 2, 2);

	displayHeap(arr, n);
}