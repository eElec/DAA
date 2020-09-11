/* LE7.3 Write a program to display an array of n integers (n>1) in O(n) time, where at every index of the array should contain the product of all elements
 * in the array except the element at the given index. No additional array
 * declaration is allowed.
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int n;
	printf("Enter Array Length: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter Array Elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int mult = 1;
	for(int i=0; i<n; i++){
		mult *= arr[i];
	}

	for(int i=0; i<n; i++){
		arr[i] = mult / arr[i];
	}

	printf("\nNew Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}