#include <stdio.h>
#include <stdio.h>
#include <time.h>

typedef struct{
	int startTime;
	int endTime;
}Activity;

void swap(Activity *a, Activity *b){
	Activity temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Activity *ac, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && ac[left].endTime > ac[largest].endTime)
		largest = left;

	if (right < n && ac[right].endTime > ac[largest].endTime)
		largest = right;

	if (largest != i)
	{
		swap(&ac[i], &ac[largest]);
		heapify(ac, n, largest);
	}
}

void heapSort(Activity *ac, int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(ac, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&ac[0], &ac[i]);
		heapify(ac, i, 0);
	}
}

void main(){
	int n;
	printf("Enter number of activities: ");
	scanf("%d", &n);

	Activity ac[n];
	printf("Enter Activity Details: \n");
	for(int i=0; i<n; i++){
		printf("Activity %d\n", i+1);
		printf("Enter Start Time: ");
		scanf("%d", &ac[i].startTime);
		printf("Enter End Time: ");
		scanf("%d", &ac[i].endTime);
	}

	clock_t clk = clock();
	//O(nlogn) sort
	heapSort(ac, n);

	int count = 1;
	int curr = 0;
	for(int i=1; i<n; i++){
		if(ac[curr].endTime <= ac[i].startTime){
			count++;
			curr = i;
		}
	}
	clk = clock() - clk;
	printf("Number of Activities that can be performed: %d\n", count);
	printf("\nTime Taken: %f\n", (float)clk/(float)CLOCKS_PER_SEC);
}