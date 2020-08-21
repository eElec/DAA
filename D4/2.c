#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int arr[], int p, int q, int r){
	//Number of elems
	int n1 = (q-p)+1;
	int n2 = (r-q);

	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) 
		L[i] = arr[p+i]; 
	for (int j = 0; j < n2; j++) 
		R[j] = arr[q + 1 + j]; 

	int i=0, j=0, k=p;
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	}
}

void MergeSort(int arr[], int p, int r){
	int q;
	if(p < r){
		q = (p + r-1	) / 2;

		MergeSort(arr, p, q);
		MergeSort(arr, q+1, r);
		Merge(arr, p, q, r);
	}
}

void main(){
	int n;
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
		MergeSort(arr, 0, n-1);
		rand = clock() - rand;

		//Data in ascending 
		clock_t asc = clock();
		MergeSort(arr, 0, n-1);
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
		MergeSort(arr, 0, n-1);
		desc = clock() - desc;

		printf("%d\t%f\t%f\t%f\n", n, (double)asc/(double)CLOCKS_PER_SEC, (double)desc/(double)CLOCKS_PER_SEC, (double)rand/(double)CLOCKS_PER_SEC);	
	}
}