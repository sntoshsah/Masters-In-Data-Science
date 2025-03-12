/*
 * Program to implement a stack using an array in C.
 * This program provides a menu-driven interface to perform
 * stack operations like push, pop, peek, and display.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

// Stack structure
typedef struct {
    int arr[MAX]; // Array to store stack elements
    int top;      // Top of the stack
} Stack;

// Function prototypes
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack stack;
    stack.top = -1; // Initialize stack as empty
    int choice, value;

    while (1) {
        // Display menu
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to push an element into the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d.\n", value);
    } else {
        s->arr[++(s->top)] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow! No elements to pop.\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to peek at the top element of the stack
int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty! No top element.\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Function to display all elements in the stack
void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
