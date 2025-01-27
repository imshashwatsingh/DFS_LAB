#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int value;
};

// global variable
struct Node *head = NULL;

void insertAtBegin(int item)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Full");
        return;
    }
    if (head == NULL)
    {
        // empty list
        head = ptr;
        head->next = head;
    }
    else
    {
        ptr->next = head;
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        head = ptr;
    }
}

void deleteLastNode()
{
    if (!head)
    {
        printf("\nEmpty List\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *ptr = head;

    while (ptr->next->next != head)
        ptr = ptr->next;
    struct Node *lastNode = ptr->next;
    ptr->next = head;
    free(lastNode);
}

int main()
{

    return 0;
}