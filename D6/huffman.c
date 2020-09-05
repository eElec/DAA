#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_SIZE 1024


struct MinHeapNode {
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;
};


struct MinHeap {
	unsigned size;
	unsigned capacity;
	struct MinHeapNode** array;
};


struct MinHeapNode* newNode(char data, unsigned freq){
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

void swap(struct MinHeapNode** a, struct MinHeapNode** b){
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

struct MinHeap* createMinHeap(unsigned capacity){
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}


void minHeapify(struct MinHeap* minHeap, int pos)
{
	int smallest = pos;
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq){
		smallest = left;
	}
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq){
		smallest = right;
	}
	if (smallest != pos) {
		swap(&minHeap->array[smallest],	&minHeap->array[pos]);
		minHeapify(minHeap, smallest);
	}
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap){
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}


void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap){
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i){
		minHeapify(minHeap, i);
	}
}



int isLeaf(struct MinHeapNode* root){
	return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}


struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
	struct MinHeapNode *left, *right, *top;
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	while (!(minHeap->size == 1)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

void printArr(int arr[], int n){
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);
	printf("\n");
}

void printCodes(struct MinHeapNode* root, int arr[], int top){
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root)) {
		printf("%c: ", root->data);
		printArr(arr, top);
	}
}


void HuffmanCodes(char data[], int freq[], int size){
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_SIZE], top = 0;
	printf("\nHuffman Code: \n");
	printCodes(root, arr, top);
}

int main()
{
	int n;
	printf("Enter number of characters: ");
	scanf("%d", &n);

	char ch[n];
	printf("Enter The Characters: ");
	for(int i=0; i<n; i++){
		scanf(" %c", &ch[i]);
	}

	int freq[n];
	printf("Enter Frequency of characters: \n");
	for(int i=0; i<n; i++){
		printf("%c : ", ch[i]);
		scanf("%d", &freq[i]);
	}

    clock_t clk = clock();
	HuffmanCodes(ch, freq, n);
	clk = clock() - clk;
	printf("\nTime Taken: %f\n", (float)clk/(float)CLOCKS_PER_SEC);

	return 0;
}