#include <stdlib.h>
#include <stdio.h>

struct DNode
{
    struct DNode *prev;
    struct DNode *next;
    int value;
};

// Global variables
struct DNode *head = NULL;
struct DNode *tail = NULL;

// Function declarations
void insertAtBegin(int item);
void insertAtEnd(int item);
void insertAfter(int target, int item);
void insertBefore(int target, int item);
void insertInSortedList(int item);
void deleteFromBegin();
void deleteFromEnd();
void deleteElement(int target);
void freeList();
void printList();

// Function to insert at the beginning
void insertAtBegin(int item)
{
    struct DNode *ptr = (struct DNode *)malloc(sizeof(struct DNode));
    if (!ptr)
    {
        printf("\nMemory Full\n");
        return;
    }

    ptr->value = item;
    ptr->prev = NULL;
    ptr->next = head;

    if (head)
    {
        head->prev = ptr;
    }
    else
    {
        // If the list is empty, update the tail as well
        tail = ptr;
    }
    head = ptr;
}

// Function to insert at the end
void insertAtEnd(int item)
{
    struct DNode *ptr = (struct DNode *)malloc(sizeof(struct DNode));
    if (!ptr)
    {
        printf("\nMemory Full\n");
        return;
    }

    ptr->value = item;
    ptr->next = NULL;

    if (!head && !tail)
    {
        // Empty list
        ptr->prev = NULL;
        head = tail = ptr;
    }
    else
    {
        // Non-empty list
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
}

// Function to insert after a given element
void insertAfter(int target, int item)
{
    struct DNode *ptr = head;

    while (ptr && ptr->value != target)
    {
        ptr = ptr->next;
    }

    if (!ptr)
    {
        printf("\nElement %d not found in the list.\n", target);
        return;
    }

    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    if (!newNode)
    {
        printf("\nMemory Full\n");
        return;
    }

    newNode->value = item;
    newNode->prev = ptr;
    newNode->next = ptr->next;

    if (ptr->next)
    {
        ptr->next->prev = newNode;
    }
    else
    {
        // If inserting at the end, update tail
        tail = newNode;
    }

    ptr->next = newNode;
}

// Function to insert before a given element
void insertBefore(int target, int item)
{
    struct DNode *ptr = head;

    while (ptr && ptr->value != target)
    {
        ptr = ptr->next;
    }

    if (!ptr)
    {
        printf("\nElement %d not found in the list.\n", target);
        return;
    }

    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    if (!newNode)
    {
        printf("\nMemory Full\n");
        return;
    }

    newNode->value = item;
    newNode->next = ptr;
    newNode->prev = ptr->prev;

    if (ptr->prev)
    {
        ptr->prev->next = newNode;
    }
    else
    {
        // If inserting at the beginning, update head
        head = newNode;
    }

    ptr->prev = newNode;
}

// Function to insert in a sorted list
void insertInSortedList(int item)
{
    if (!head || item < head->value)
    {
        insertAtBegin(item);
        return;
    }

    struct DNode *ptr = head;

    while (ptr->next && ptr->next->value < item)
    {
        ptr = ptr->next;
    }

    insertAfter(ptr->value, item);
}

// Function to delete from the beginning
void deleteFromBegin()
{
    if (!head)
    {
        printf("\nList is already empty.\n");
        return;
    }

    struct DNode *temp = head;

    head = head->next;
    if (head)
    {
        head->prev = NULL;
    }
    else
    {
        // If the list becomes empty, update tail
        tail = NULL;
    }

    free(temp);
    printf("\nDeleted element from the beginning.\n");
}

// Function to delete from the end
void deleteFromEnd()
{
    if (!tail)
    {
        printf("\nList is already empty.\n");
        return;
    }

    struct DNode *temp = tail;

    tail = tail->prev;
    if (tail)
    {
        tail->next = NULL;
    }
    else
    {
        // If the list becomes empty, update head
        head = NULL;
    }

    free(temp);
    printf("\nDeleted element from the end.\n");
}

// Function to delete a given element
void deleteElement(int target)
{
    struct DNode *ptr = head;

    while (ptr && ptr->value != target)
    {
        ptr = ptr->next;
    }

    if (!ptr)
    {
        printf("\nElement %d not found in the list.\n", target);
        return;
    }

    if (ptr->prev)
    {
        ptr->prev->next = ptr->next;
    }
    else
    {
        // If deleting the first node, update head
        head = ptr->next;
    }

    if (ptr->next)
    {
        ptr->next->prev = ptr->prev;
    }
    else
    {
        // If deleting the last node, update tail
        tail = ptr->prev;
    }

    free(ptr);
    printf("\nDeleted element %d from the list.\n", target);
}

// Function to free the entire list
void freeList()
{
    if (!head)
    {
        printf("\nAlready Empty List : Doubly\n");
        return;
    }

    struct DNode *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    head = tail = NULL;
    printf("\nList Cleared!\n");
}

// Function to print the list
void printList()
{
    if (!head)
    {
        printf("\nEmpty List : Doubly :\n");
        return;
    }

    struct DNode *ptr = head;
    printf("Doubly Linked List : X<-");
    while (ptr)
    {
        if (ptr->next == NULL)
        {
            printf(" %d ->", ptr->value);
        }
        else
        {
            printf(" %d <=>", ptr->value);
        }
        ptr = ptr->next; // Move to the next node
    }
    printf(" X\n");
}

// Main function for testing
int main()
{
    insertAtBegin(10);
    insertAtBegin(20);
    insertAtEnd(5);
    insertAtEnd(1);

    printList(); // Output: Doubly Linked List : X<- 20 <=> 10 <=> 5 <=> 1 <=> X

    // freeList();  // Clear the list
    printList(); // Output: Empty List : Doubly :

    int choice, value, target;

    while (1)
    {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert After an Element\n");
        printf("4. Insert Before an Element\n");
        printf("5. Insert in Sorted List\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete a Specific Element\n");
        printf("9. Print List\n");
        printf("10. Clear List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertAtBegin(value);
            break;

        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 3:
            printf("Enter the element after which to insert: ");
            scanf("%d", &target);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertAfter(target, value);
            break;

        case 4:
            printf("Enter the element before which to insert: ");
            scanf("%d", &target);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertBefore(target, value);
            break;

        case 5:
            printf("Enter the value to insert in a sorted list: ");
            scanf("%d", &value);
            insertInSortedList(value);
            break;

        case 6:
            deleteFromBegin();
            break;

        case 7:
            deleteFromEnd();
            break;

        case 8:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            deleteElement(value);
            break;

        case 9:
            printList();
            break;

        case 10:
            freeList();
            break;

        case 11:
            printf("Exiting program.\n");
            freeList();
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
