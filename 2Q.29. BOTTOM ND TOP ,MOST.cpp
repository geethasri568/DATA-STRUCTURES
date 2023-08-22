#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}

int addBottomAndTop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot add.\n");
        return -1;
    }

    int bottom = stack->items[0];
    int top = stack->items[stack->top];
    return bottom + top;
}

int main() {
	
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Bottom + Top: %d\n", addBottomAndTop(&stack));

    
    while (!isEmpty(&stack)) {
        pop(&stack);
    }

    return 0;
}
