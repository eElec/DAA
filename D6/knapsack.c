#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	float weight;
	float price;
	float priceDensity;
}Knapsack;

void swap(Knapsack *a, Knapsack *b){
	Knapsack temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Knapsack *ks, int n, int i)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && ks[left].priceDensity < ks[smallest].priceDensity)
		smallest = left;

	if (right < n && ks[right].priceDensity < ks[smallest].priceDensity)
		smallest = right;

	if (smallest != i)
	{
		swap(&ks[i], &ks[smallest]);
		heapify(ks, n, smallest);
	}
}

void heapSort(Knapsack *ks, int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(ks, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&ks[0], &ks[i]);
		heapify(ks, i, 0);
	}
}
void main(){
	int n;
	printf("Enter Number of Items: ");
	scanf("%d", &n);

	Knapsack ks[n];
	printf("Enter information: \n");
	for(int i=0; i<n; i++){
		printf("Item %d: \n", i+1);
		printf("Enter Weight: ");
		scanf("%f", &ks[i].weight);
		printf("Enter Price: ");
		scanf("%f", &ks[i].price);

		ks[i].priceDensity = ks[i].price / ks[i].weight;
	}

	float MaxWeight;
	printf("Enter Max Weight: ");
	scanf("%f", &MaxWeight);

	clock_t clk = clock();
	//O(nLogn) sort
	heapSort(ks, n);

	float MaxPrice = 0;
	int i;
	for( i=0; i<n; i++){
		if(MaxWeight > 0 && ks[i].weight <= MaxWeight){
			MaxWeight -= ks[i].weight;
			MaxPrice += ks[i].price;
		}
		else{
			break;
		}
	}
	if(MaxWeight > 0){
		MaxPrice += ks[i].price*(MaxWeight/ks[i].weight);
	}
	clk = clock() - clk;
	printf("Max Price: %f\n", MaxPrice);
	printf("\nTime Taken: %f\n", (float)clk/(float)CLOCKS_PER_SEC);
}