#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void udf1(int arr[], int n){
	for(int i=0; i<n-1; i++){
		int count = 1;
		for(int j=i+1; j<n; j++){
			if(arr[i] == arr[j]){
				count++;
				if(count >= (n/2)){
					printf("%d occurs more than n/2=%d times.\n", arr[i], n/2);
					break;
				}
			}
		}
	}
}

void udf2(int arr[], int n){
	//Assuming value in array <=1000
	int count[1001];
	for(int i=0; i<1001; i++){
		count[i] = 0;
	}
	for(int i=0; i<n; i++){
		count[arr[i]]+=1;
		if(count[arr[i]] > n/2){
			printf("%d occurs more than n/2=%d times.\n", arr[i], n/2);
		}
	}
}

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d values: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nFunction with O(n^2) time and no additional space\n");
	udf1(arr, n);
	printf("\nFunction with O(n) time and O(1) space complexity\n");
	udf2(arr, n);
}