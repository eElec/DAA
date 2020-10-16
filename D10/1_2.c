// Representation of graph in Adjacency List

#include <stdio.h>
#include <stdlib.h>

struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 

struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{
	src -= 1, dest -= 1;
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 

void main(){
    struct Graph *adjGraph = createGraph(6); 
	addEdge(adjGraph, 1, 2);
	addEdge(adjGraph, 1, 3);
	addEdge(adjGraph, 2, 4);
	addEdge(adjGraph, 2, 5);
	addEdge(adjGraph, 3, 4);
	addEdge(adjGraph, 3, 5);
	addEdge(adjGraph, 4, 6);
	addEdge(adjGraph, 4, 5);
	addEdge(adjGraph, 5, 6);

	for (int i = 0; i < adjGraph->V; ++i)     { 
        struct AdjListNode* curr = adjGraph->array[i].head; 
        printf("Vertex %d ", i+1); 
        while (curr)        { 
            printf("-> %d ", curr->dest + 1); 
            curr = curr->next; 
        } 
        printf("\n"); 
    } 
}