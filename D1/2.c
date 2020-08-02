#include <stdio.h>
#include <math.h>

int getIndex(int arr[][2], int n, int val){
	for(int i=0; i<n; i++){
		if(arr[i][0] == val){
			return i;
		}
	}
	return -1;
}

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	//Array to store duplicate values [[<value>, <number of times it repeated>]]
	int dups = 0;
	int darr[n][2];
	for(int i=0; i<n; i++){
		darr[i][1] = 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int loc = getIndex(darr, n, arr[j]);
			if(arr[i] == arr[j]){
				if(loc == -1){
					darr[dups][0] = arr[j];
					darr[dups][1] += 1;
					dups++;
				}
				else{
					darr[loc][1] += 1;
				}
			}
		}
	}

	// darr[i][1] = sqrt(darr[i][1]) wasn't working
	for(int i=0; i<dups; i++){
		printf("\n%d : %.0f", darr[i][0], sqrt(darr[i][1]));
	}

	int max[2];
	max[0] = darr[0][0];
	max[1] = darr[0][1];
	for (int i = 0; i < dups; i++)
	{
		if(max[1] < darr[i][1]){
			max[0] = darr[i][0];
			max[1] = darr[i][1];
		}
	}
	
	printf("\n\nMax Repeated Term is %d repeated %.0f times", max[0], sqrt(max[1]));
}