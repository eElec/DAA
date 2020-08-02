#include <stdio.h>
int n;

// (a)
void nonZero(int arr[50][50], int n){
	int nz = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] == 0){
				nz++;
			}
		}
	}
	printf("\nNumber of Non Zero Elements are: %d", (n*n) - nz);
}

// (b)
void sumLeadingDiagonal(int arr[50][50], int n){
	int sum = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			sum+=arr[i][j];
		}
	}
	printf("\nSum of Upper Diagonal Elements are: %d", sum);
}

// (c)
void DisplayMinorDiagonal(int arr[50][50], int n){
	printf("\nElements below minor diagonal: ");
	for(int i=0; i<n; i++){
		for(int j=n-i; j<n; j++){
			printf("%d ", arr[i][j]);
		}
	}
}

// (d)
void productDiagonal(int arr[50][50], int n){
	int prod = 1;
	for(int i=0; i<n; i++){
		prod*=arr[i][i];
		prod*=arr[i][n-i-1];
	}
	prod/=arr[(n-1)/2][(n-1)/2];
	printf("\nProduct of Diagonal Elements are: %d", prod);
}
void main(){
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int arr[50][50];
	printf("Enter elements: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("arr[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}

	printf("Original Array: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	nonZero(arr, n);
	sumLeadingDiagonal(arr, n);
	DisplayMinorDiagonal(arr, n);
	productDiagonal(arr, n);
}