/*
 * Program to convert an infix expression to postfix using a stack in C.
 * This program converts a given infix expression to its equivalent postfix notation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
int precedence(char ch);
void infixToPostfix(char *infix, char *postfix);

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
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

// Function to get the precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i]; // Operand goes directly to postfix
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } else {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }
    
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
