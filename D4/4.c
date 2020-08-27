#include <stdio.h>
#include <limits.h>
int MIN, MAX;

void findMinMax(int arr[], int l, int h){
	if(h > l){
		int mid = (h+l) / 2;
		findMinMax(arr, l, mid);
		findMinMax(arr, mid+1, h);
	}
	else{
		if(arr[l] > arr[h]){
			if(arr[l] > MAX){
				MAX = arr[l];
			}
			if(arr[h] < MIN){
				MIN = arr[h];
			}
		}
		else{
			if(arr[h] > MAX){
				MAX = arr[l];
			}
			if(arr[l] < MIN){
				MIN = arr[h];
			}
		}
	}
}

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter Elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	MIN = INT_MAX;
	MAX = INT_MIN;
	findMinMax(arr, 0, n-1);

	printf("Min: %d\nMax: %d\n", MIN, MAX);
}