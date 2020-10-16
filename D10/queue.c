#define SIZE 30

struct Queue{
	int items[SIZE];
	int front;
	int rear;
};

struct Queue* createQueue() {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(struct Queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct Queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct Queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      // printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct Queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    for (i = q->front; i < q->rear + 1; i++) {
      // printf("%d ", q->items[i]+1);
    }
  }
}
