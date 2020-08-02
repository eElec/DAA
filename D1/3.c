// We can seperate the even and odd numbers into two array and then merge them.
#include <stdio.h>

void main(){
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	//Odd and even array can also be populated while taking the inputs
	int arr[n];
	printf("Enter %d numbers: ", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int e=0, o=0;
	int even[n], odd[n];

	for(int i=0; i<n; i++){
		if(arr[i]%2 == 0){
			even[e] = arr[i];
			e++;
		}
		else{
			odd[o] = arr[i];
			o++;
		}
	}

	int arr2[n];
	int temp1 = 0, temp2 = 0;
	int k=0;
	while(temp1 < e && temp2 < o){
		arr2[k] = even[temp1];
		temp1++;
		k++;
		arr2[k] = odd[temp2];
		temp2++;
		k++;
	}

	while(temp1 < e){
		arr2[k] = even[temp1];
		temp1++;
		k++;
	}

	while(temp2 < o){
		arr2[k] = odd[temp2];
		temp2++;
		k++;
	}

	printf("\n\nOld Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}

	printf("\nNew Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr2[i]);
	}
}