#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct{
	int heap[MAX_SIZE];
	int heapsize;
}Heap;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getParent(int pos){
	return ((pos-1)/2);
}
int getLeftChild(int pos){
	return pos*2 + 1;
}
int getRightChild(int pos){
	return pos*2 + 2;
}

void maxHeapify(Heap *hp, int pos){
	if(pos > (hp->heapsize)/2 && pos<hp->heapsize){
		// if the parent is smaller than either of the child
		if(hp->heap[pos] < hp->heap[getLeftChild(pos)] || hp->heap[pos] < hp->heap[getRightChild(pos)]){

			//Swap with largest
			if(hp->heap[getLeftChild(pos)] > hp->heap[getRightChild(pos)]){
				swap(&hp->heap[pos], &hp->heap[getLeftChild(pos)]);
				maxHeapify(hp, getLeftChild(pos));
			}
			else{
				swap(&hp->heap[pos], &hp->heap[getRightChild(pos)]);
				maxHeapify(hp, getRightChild(pos));
			}
		}
	}
}

void removeMax(Heap *hp){
	hp->heapsize--;
	hp->heap[0] = hp->heap[hp->heapsize];
	maxHeapify(hp, 0);
}

void insertElement(Heap *hp, int elem){
	int n = hp->heapsize;
	hp->heap[n] = elem;
	
	//Swap with parent if larger
	while(hp->heap[n] > hp->heap[getParent(n)] && n > 0){
		swap(&hp->heap[n], &hp->heap[getParent(n)]);
		n = getParent(n);
	}
	hp->heapsize++;
}

int getMax(Heap *hp){
	if(hp->heapsize == 0){
		return -1;
	}
	return hp->heap[0];
}

void increaseVal(Heap *hp, int pos, int val)
{
	if(pos > hp->heapsize){
		return;
	}
   hp->heap[pos] = val;
   maxHeapify(hp, 0);
}

void printHeap(Heap *hp){
	printf("Parent\nLeft\nRight");
	for(int i=0; i<hp->heapsize/2; i++){
		printf("%d\t%d\t%d", hp->heap[i], hp->heap[getLeftChild(i)], hp->heap[getRightChild(i)]);
	}
}

void main(){
	Heap hp;
	hp.heapsize = 0;
	int n;
	printf("Enter Number of Elements: ");
	scanf("%d", &n);

	printf("Enter Elements: ");
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		insertElement(&hp, 	t);
	}

	for(int i=0; i<hp.heapsize; i++){
		printf("%d ", hp.heap[i]);
	}

	printf("\nMaximum Element: %d\n", getMax(&hp));
	printf("Removing Max Element...\n");
	removeMax(&hp);
	for(int i=0; i<hp.heapsize; i++){
		printf("%d ", hp.heap[i]);
	}
	printf("\n");
	increaseVal(&hp, 1, 12);
	for(int i=0; i<hp.heapsize; i++){
		printf("%d ", hp.heap[i]);
	}
	printf("\n");	
}