#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSortMax(int arr[], int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void main(){
	printf("N\tTime\n");
	for(int n=1000; n<=10000; n+=1000){
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 5000;
		}
		time_t rand = clock();
		heapSortMax(arr, n);
		rand = clock() - rand;

		printf("%d\t%f\n", n, (float)rand/(float)CLOCKS_PER_SEC);
	}
}