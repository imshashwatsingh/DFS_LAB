#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack Implementation using Linked List

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *nodePtr;

// Global Variables
/*
    head will act as tail here and making it global
*/

nodePtr head = NULL;

bool isEmpty()
{
    return head == NULL;
}

nodePtr createNode(int item)
{

    nodePtr newItem = (nodePtr)malloc(sizeof(struct Node));

    if (!newItem)
    {
        printf("\nMemory Full\n");
        return NULL;
    }

    newItem->data = item;
    newItem->next = NULL;

    return newItem;
}

void push(int item)
{

    nodePtr newItem = createNode(item);

    newItem->next = head;
    head = newItem;

    printf("\n %d,Item Pushed !\n", item);
}

int pop()
{
    if (!isEmpty())
    {
        nodePtr temp = head;
        head = head->next;
        int popValue = temp->data;
        free(temp);
        return popValue;
    }
    printf("\n Stack UnderFlow !\n");
    return -1;
}

int peek()
{
    
        if (isEmpty())
        {
            printf("\nStack is empty !\n");
            return -1;
        }
        return head->data;
}

void display()
{
    if (isEmpty())
    {
        printf("\nStack is empty !\n");
        return;
    }
    printf("\nStack contents:\n");
    for (nodePtr temp = head; temp != NULL; temp = temp->next)
    {
        if (temp == head)
        {
            printf("%d <- top\n", temp->data); // Label the top element
        }
        else
        {
            printf("%d\n", temp->data);
        }
    }
}

int main()
{

    int choice, value, poppedValue;

    do
    {
        printf("\n========== Stack Menu ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            // Clear invalid input
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("Invalid input. Please enter a valid integer.\n");
                continue;
            }
            push(value);
            break;

        case 2:
            poppedValue = pop();
            if (poppedValue != -1)
            {
                printf("\nPopped value: %d\n", poppedValue);
            }
            break;

        case 3:
            value = peek();
            if (value != -1)
            {
                printf("\nTop of the stack: %d\n", value);
            }
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;

    return 0;
}