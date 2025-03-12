/*
 * Program to check for balanced brackets using a stack in C.
 * This program verifies if an expression has properly matched brackets.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Define the maximum size of the stack

// Stack structure
typedef struct {
    char arr[MAX]; // Array to store stack elements
    int top;       // Top of the stack
} Stack;

// Function prototypes
void push(Stack *s, char ch);
char pop(Stack *s);
char peek(Stack *s);
int isMatchingPair(char open, char close);
int isBalanced(char *expr);

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    scanf("%s", expression);
    
    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }
    return 0;
}

// Function to push an element onto the stack
void push(Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++(s->top)] = ch;
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to check if brackets match
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

// Function to check if an expression is balanced
int isBalanced(char *expr) {
    Stack stack;
    stack.top = -1;
    
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (stack.top == -1 || !isMatchingPair(pop(&stack), expr[i])) {
                return 0; // Not balanced
            }
        }
    }
    return stack.top == -1; // If stack is empty, it's balanced
}
