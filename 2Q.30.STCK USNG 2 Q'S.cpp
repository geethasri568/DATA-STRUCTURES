#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue {
    int *arr;
    int front, rear, size;
};
struct Queue* createQueue(int capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->size = capacity;
    queue->front = queue->rear = -1;
    return queue;
}
bool isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}
void enqueue(struct Queue *queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}
struct Stack {
    struct Queue *q1;
    struct Queue *q2;
};
struct Stack* createStack(int capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}
void push(struct Stack *stack, int value) {
    enqueue(stack->q2, value);
    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}
int pop(struct Stack *stack) {
    return dequeue(stack->q1);
}

int main() {
	
    struct Stack *stack = createStack(10);

    push(stack, 3);
    push(stack, 5);
    push(stack, 8);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    free(stack->q1->arr);
    free(stack->q1);
    free(stack->q2->arr);
    free(stack->q2);
    free(stack);

    return 0;
}
