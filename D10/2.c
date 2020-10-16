// DFS using iterative method

#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int arr[30];
	int top;
};

int top(struct Stack s){
	return s.arr[s.top];
}
void pop(struct Stack *s){
	s->top--;
}
void push(struct Stack *s, int n){
	s->top++;
	s->arr[s->top] = n;
}

void DFS(int adj[][6]){
	struct Stack visitStack;

	visitStack.top = 0;
	visitStack.arr[visitStack.top] = 0;

	int *visited = (int *)calloc(6, sizeof(int));
	while(visitStack.top != -1){
		int node = top(visitStack);
		pop(&visitStack);

		if(visited[node] == 0){
			printf("%d ", node+1);
			visited[node] = 1;
		}

		for(int i=0; i<6; i++){
			if(visited[i]){
				continue;
			}
			if(adj[node][i] == 1){
				push(&visitStack, i);
			}
		}
	}
}

void addEdge(int adj[][6], int a, int b){
	adj[a-1][b-1] = 1;
	adj[b-1][a-1] = 1;
}

void main(){
	int adjArr[6][6];

	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			adjArr[i][j] = 0;
		}
	}

	addEdge(adjArr, 1, 2);
	addEdge(adjArr, 1, 3);
	addEdge(adjArr, 2, 4);
	addEdge(adjArr, 2, 5);
	addEdge(adjArr, 3, 4);
	addEdge(adjArr, 3, 5);
	addEdge(adjArr, 4, 6);
	addEdge(adjArr, 5, 6);
	
	printf("DFS: ");
	DFS(adjArr);
	printf("\n");
}