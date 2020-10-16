// DFS using iterative method

#include <stdio.h>
#include <stdlib.h>

#include "queue.c"
#include "createGraph.c"

#define SIZE 30

void BFS(struct Graph* graph, int startVertex) {
  struct Queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("%d ", currentVertex + 1);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

void main(){
	struct Graph* adjGraph = createGraph(6);

	addEdge(adjGraph, 1, 2);
	addEdge(adjGraph, 1, 3);
	addEdge(adjGraph, 2, 4);
	addEdge(adjGraph, 2, 5);
	addEdge(adjGraph, 3, 4);
	addEdge(adjGraph, 3, 5);
	addEdge(adjGraph, 4, 6);
	addEdge(adjGraph, 5, 6);

	printf("BFS: ");
	BFS(adjGraph, 0);
	printf("\n");
}