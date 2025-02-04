#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack Implementation using Arrays !

// Global Variables
#define n 10 // Define stack size

int stack[n]; // Stack array
int top = -1; // Top pointer

// Function to check if the stack is empty
bool isEmpty() { 
    return top == -1; 
}

// Function to check if the stack is full
bool isFull() { 
    return top == n - 1; 
}

// Push function to insert an element into the stack
void push(int item) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot push %d\n", item);
        return;
    }
    stack[++top] = item;
    printf("\n%d pushed into the stack.\n", item);
}

// Pop function to remove and return the top element of the stack
int pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Cannot pop.\n");
        return -1; // Return a sentinel value
    }
    return stack[top--];
}

// Peek function to get the top element of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("\nStack is empty, no top element.\n");
        return -1;
    }
    return stack[top];
}

// Display function to show all elements of the stack
void display() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack contents:\n");
    for (int i = top; i >= 0; i--) {
        if (i == top) {
            printf("%d <- top\n", stack[i]);  // Label the top element
        } else {
            printf("%d\n", stack[i]);
        }
    }
}


// Menu-driven program
int main() {
    int choice, value;
    
    while (1) {
        printf("\nStack Operations Menu:\n");
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
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("\nPopped element: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("\nTop element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
