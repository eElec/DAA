#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSortAsc(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		while (key < arr[j - 1] && j > 0)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void InsertionSortDesc(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		while (key > arr[j - 1] && j > 0)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void main(){
	int n;
	int arr[20000];
	printf("n \tBest Case \tWorst Case \tAverage Case\n");
	for(int n=1000; n<=10000; n+=1000){
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
		}

		// Average case
		clock_t avg = clock();
		InsertionSortAsc(arr, n);
		avg = clock() - avg;

		// Best Case - Already sorted array
		clock_t best = clock();
		InsertionSortAsc(arr, n);
		best = clock() - best;

		// Worst Case - Array sorted in opposite way
		clock_t worst = clock();
		InsertionSortDesc(arr, n);
		worst = clock() - worst;

		printf("%d\t%f\t%f\t%f\n", n, (double)best / (double)CLOCKS_PER_SEC, (double)worst / (double)CLOCKS_PER_SEC, (double)avg / (double)CLOCKS_PER_SEC);
	}
}