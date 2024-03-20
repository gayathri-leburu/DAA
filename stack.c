#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the stack

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* s) {
    s->top = -1;
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

bool isStackFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int x) {
    if (!isStackFull(s)) {
        s->top++;
        s->stack[s->top] = x;
    } else {
        printf("Stack is full, cannot push %d\n", x);
    }
}

int pop(Stack* s) {
    if (!isStackEmpty(s)) {
        int x = s->stack[s->top];
        s->top--;
        return x;
    } else {
        printf("Stack is empty, cannot pop\n");
        return -1; // Or any appropriate value indicating failure
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 4);
    push(&stack, 1);
    push(&stack, 3);

    printf("Popped from stack: %d\n", pop(&stack));
    printf("Popped from stack: %d\n", pop(&stack));
    printf("Popped from stack: %d\n", pop(&stack));

    return 0;
}

***********
OUTPUT
***********
  
S 4 1 3
  
Popped from stack: 3
Popped from stack: 1
Popped from stack: 4
