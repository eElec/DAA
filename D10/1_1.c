// Representation of graph in Adjacency Matrix

#include <stdio.h>
#include <stdlib.h>

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

	for(int i=0; i<=6; i++){
		printf("%d\t", i);
	}
	printf("\n");
	for(int i=0; i<6; i++){
		printf("%d\t", i);
		for(int j=0; j<6; j++){
			printf("%d\t", adjArr[i][j]);
		}
		printf("\n");
	}
}