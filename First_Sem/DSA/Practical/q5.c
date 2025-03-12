/*
 * Program to convert an infix expression to postfix and evaluate a postfix expression using a stack in C.
 * This program converts a given infix expression to its equivalent postfix notation
 * and evaluates the resulting postfix expression.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Define the maximum size of the stack

// Stack structure for characters
typedef struct {
    char arr[MAX]; // Array to store stack elements
    int top;       // Top of the stack
} Stack;

// Stack structure for integers
typedef struct {
    int arr[MAX]; // Array to store stack elements
    int top;      // Top of the stack
} IntStack;

// Function prototypes
void push(Stack *s, char ch);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char ch);
void infixToPostfix(char *infix, char *postfix);
int evaluatePostfix(char *postfix);
void pushInt(IntStack *s, int value);
int popInt(IntStack *s);

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);
    
    return 0;
}

// Function to push an element onto the character stack
void push(Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++(s->top)] = ch;
    }
}

// Function to pop an element from the character stack
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

// Function to return the top element of the stack without popping it
char peek(Stack *s) {
    if (s->top == -1) {
        return '\0'; // Return null character if stack is empty
    }
    return s->arr[s->top];
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

// Function to push an integer onto the integer stack
void pushInt(IntStack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++(s->top)] = value;
    }
}

// Function to pop an integer from the integer stack
int popInt(IntStack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return 0;
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    IntStack stack;
    stack.top = -1;
    int i, op1, op2, result;
    
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            pushInt(&stack, postfix[i] - '0'); // Convert char to int
        } else {
            op2 = popInt(&stack);
            op1 = popInt(&stack);
            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            pushInt(&stack, result);
        }
    }
    return popInt(&stack);
}
