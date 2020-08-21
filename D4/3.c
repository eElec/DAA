#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qsPartition(int arr[], int p, int r){
	int pivot = arr[r];
	int i = p - 1;
	for(int j=p; j<=r-1; j++){
		if(arr[j] < pivot){
			i++;
			//swap
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quickSort(int arr[], int p, int r){
	if(p<r){
		int q = qsPartition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

void main(){
	int n = 10;
	int arr[n];
	printf("n \tBest Case \tWorst Case \tAverage Case\n");
	for(int n=1000; n<=10000; n+=1000){
		int arr[n];
		srand(clock());
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
		}

		//Random
		clock_t rand = clock();
		quickSort(arr, 0, n-1);
		rand = clock() - rand;

		//Data in ascending 
		clock_t asc = clock();
		quickSort(arr, 0, n-1);
		asc = clock() - asc;

		//Data in descending
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(arr[i] < arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		clock_t desc = clock();
		quickSort(arr, 0, n-1);
		desc = clock() - desc;

		printf("%d\t%f\t%f\t%f\n", n, (double)asc/(double)CLOCKS_PER_SEC, (double)desc/(double)CLOCKS_PER_SEC, (double)rand/(double)CLOCKS_PER_SEC);	
	}
}