#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack {
    int *arr;
    int top;
    int size;
};
struct Stack* createStack(int capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->size = capacity;
    stack->top = -1;
    return stack;
}
bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}
bool isFull(struct Stack *stack) {
    return (stack->top == stack->size - 1);
}
void push(struct Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->arr[stack->top] = value;
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}
int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        int value = stack->arr[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}
struct Queue {
    struct Stack *stack1; 
    struct Stack *stack2; 
};
struct Queue* createQueue(int capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}
void enqueue(struct Queue *queue, int value) {
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    push(queue->stack1, value);
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}
int dequeue(struct Queue *queue) {
    if (!isEmpty(queue->stack1)) {
        return pop(queue->stack1);
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
}

int main() {
	
    struct Queue *queue = createQueue(10);

    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 8);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    free(queue->stack1->arr);
    free(queue->stack1);
    free(queue->stack2->arr);
    free(queue->stack2);
    free(queue);

    return 0;
}
