#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to shift elements left when queue is full and front > 0
void leftShift() {
    if (front > 0) {
        int j = 0;
        for (int i = front; i <= rear; i++) {
            queue[j++] = queue[i];
        }
        rear = j - 1;
        front = 0;
    }
}

// Function to check if queue is empty
bool isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
bool isFull() {
    return (rear == SIZE - 1);
}

// Function to insert element in queue
void enQueue(int value) {
    if (isFull()) {
        if (front > 0) { 
            leftShift();
        } else {
            printf("\nQueue is Full! Cannot insert %d.\n", value);
            return;
        }
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("\nEnqueued: %d\n", value);
}

// Function to delete element from queue
void deQueue() {
    if (isEmpty()) {
        printf("\nQueue is Empty! Cannot dequeue.\n");
        return;
    }
    printf("\nDequeued Element: %d\n", queue[front]);
    if (front == rear) {  // If only one element was in queue
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to peek at the front element
void peep() {
    if (!isEmpty()) {
        printf("\nFront Element: %d\n", queue[front]);
    } else {
        printf("\nQueue is Empty!\n");
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue Elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations Menu:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peep (Front Element)");
        printf("\n4. Display Queue");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
