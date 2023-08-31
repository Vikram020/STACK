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
        printf("Stack is full. Cannot push %d.\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("Pushed %d onto the stack.\n", item);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, item;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}
