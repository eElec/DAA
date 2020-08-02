#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Sorting then printing second and second last element
void method1(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if (arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for(int i=n-2; i>0; i--){
		if(arr[i] != arr[i+1]){
			printf("\nSecond Largest Element: %d", arr[i]);
			break;
		}
	}
	for(int i=1; i<n; i++){
		if(arr[i] != arr[i-1]){
			printf("\nSecond Smallest Element: %d", arr[i]);
			break;
		}
	}

}

//Using two variables
void method2(int arr[], int n){
	int max = arr[0], min = arr[0];
	int max2 = INT_MIN, min2 = INT_MAX;
	for(int i=0; i<n; i++){
		if(max < arr[i]){
			max = arr[i];
		}
		if(min > arr[i]){
			min = arr[i];
		}
	}

	for(int i=0; i<n; i++){
		if(max2 < arr[i] && arr[i] != max){
			max2 = arr[i];
		}
		if(min2 > arr[i] && arr[i] != min){
			min2 = arr[i];
		}
	}

	printf("\nSecond Largest Element: %d", max2);
	printf("\nSecond Smallest Element: %d", min2);
}

void main(){
	int n;
	printf("Enter Size of Array: ");
	scanf("%d", &n);

	int r_min, r_max;
	printf("Enter Range of Numbers in the array:");
	printf("\nMin: ");	scanf("%d", &r_min);
	printf("Max: ");	scanf("%d", &r_max);
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i] = r_min + rand()%(r_max - r_min + 1);
	}

	printf("Original Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\nFirst Method: ");
	method1(arr, n);
	printf("\nSecond Method: ");
	method2(arr, n);
}