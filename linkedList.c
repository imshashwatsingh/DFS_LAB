#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *next;
};

// functionalities

void printList(struct Node *head);

struct Node *addHead(int item, struct Node *head);

struct Node *deleteHead(struct Node *head);

struct Node *deletLastNode(struct Node *head);

struct Node *deleteItem(int target, struct Node *head);

struct Node *deleteAtIndex(int index, struct Node *head);

struct Node *removeNthFromEnd(struct Node *head, int n);

struct Node *insertNode(int item, struct Node *head);

bool isElementExists(int target, struct Node *head);

struct Node *search(int target, struct Node *head);

struct Node *insertAfter(int item, int after, struct Node *head);

struct Node *insertBefore(int item, int before, struct Node *head);

void freeList(struct Node *head);


void printList(struct Node *head)
{
    if (!head)
    {
        printf("Empty List");
    }
    else
    {
        printf("\n\n List : ");
        struct Node *ptr = head;
        while (ptr)
        {
            printf("%d -> ", ptr->value);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

struct Node *addHead(int item, struct Node *head)
{
    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    if (!newItem)
    {
        printf("Memory Full");
        return head;
    }
    newItem->value = item;
    newItem->next = head;
    head = newItem;
    return head;
}

struct Node *deleteHead(struct Node *head)
{
    if (head)
    {
        struct Node *ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else
    {
        printf("\nEmpty List\n");
    }
    return head;
}

struct Node *deletLastNode(struct Node *head)
{

    if (!head) // Empty list
    {
        printf("\nEmpty List\n");
        return NULL;
    }

    if (!head->next) // Single node case
    {
        free(head);
        return NULL;
    }

    struct Node *ptr = head;
    while (ptr->next->next) // Traverse to second last node
    {
        ptr = ptr->next;
    }

    free(ptr->next);  // Free last node
    ptr->next = NULL; // Update second last node's next
    return head;
}

struct Node *deleteItem(int target, struct Node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty List\n");
        return NULL;
    }

    // Handle deletion of the head node
    while (head && head->value == target)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    struct Node *curr = head, *prev = NULL;

    // Traverse and delete other occurrences
    while (curr)
    {
        if (curr->value == target)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

struct Node *deleteAtIndex(int index, struct Node *head)
{
    if (!head)
    {
        printf("\nEmpty List\n");
        return NULL;
    }

    if (index < 0)
    {
        printf("\nInvalid Index\n");
        return head;
    }

    // If deleting the head node
    if (index == 0)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    struct Node *previous = NULL;
    int count = 0;

    // Traverse the list to find the node at the given index
    while (current && count < index)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (!current)
    {
        printf("\nIndex out of bounds\n");
        return head;
    }

    // Remove the node
    previous->next = current->next;
    free(current);

    return head;
}

struct Node *removeNthFromEnd(struct Node *head, int n)
{
    if (!head)
        return NULL; // Handle empty list

    // Calculate the length of the list
    int length = 0;
    struct Node *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }

    // Handle the case where the head needs to be removed
    if (n == length)
    {
        struct Node *toDelete = head;
        head = head->next; // Move the head pointer
        free(toDelete);
        return head;
    }

    // Find the node just before the one to delete
    int targetIndex = length - n; // 1-based index
    temp = head;
    for (int i = 1; i < targetIndex;
         i++)
    { // Stop at the (targetIndex-1) node
        temp = temp->next;
    }

    // Delete the target node
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

struct Node *insertNode(int item, struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Full!\n");
        return head;
    }

    ptr->value = item;
    ptr->next = NULL;

    if (head == NULL)
    {
        return ptr; // New head for an empty list
    }

    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    return head;
}

bool isElementExists(int target, struct Node *head)
{

    if (!head)
    {
        printf("Empty List\n");
        return false;
    }

    if (head->value == target)
        return true;

    for (struct Node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->value == target)
        {
            printf("Element Found\n");
            return true;
        }
    }
    return false;
}

struct Node *search(int target, struct Node *head)
{
    if (!head)
    {
        printf("Empty List !\n");
        return NULL;
    }
    else
    {
        for (struct Node *ptr = head; ptr->next != NULL; ptr = ptr->next)
        {
            if (ptr->value == target)
            {
                return ptr;
            }
        }
    }
}

struct Node *insertAfter(int item, int after, struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Full !");
    }
    else
    {
        ptr->value = item;
        struct Node *temp = head;
        while (temp && temp->value != after)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            printf("After does not exist !\n");
        }
        else
        {
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
    return head;
}

struct Node *insertBefore(int item, int before, struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Full!\n");
        return head;
    }

    ptr->value = item;

    if (!head) // Empty list
    {
        printf("Empty List\n");
        free(ptr);
        return head;
    }

    if (head->value == before) // Insert before head
    {
        ptr->next = head;
        return ptr;
    }

    struct Node *temp = head;
    while (temp->next && temp->next->value != before)
    {
        temp = temp->next;
    }

    if (!temp->next) // Target not found
    {
        printf("Value %d not found\n", before);
        free(ptr);
        return head;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    return head;
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    bool flag = true;
    int choice, item, after, before;

    while (flag)
    {
        printf("\n\n------------- Singly Linked List -----------\n\n");
        printf("Operations :\n");
        printf("1: Print List\n");
        printf("2: Insert New Node (at the end)\n");
        printf("3: Insert New Node (at the start)\n");
        printf("4: Insert New Node After\n");
        printf("5: Insert New Node Before\n");
        printf("6: Delete Head\n");
        printf("7: Delete From End (last node) \n");
        printf("10: Exit\n");
        printf("\n---> Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList(head);
            break;

        case 2:
            printf("Enter item to be added at the end: ");
            scanf("%d", &item);
            head = insertNode(item, head);
            printList(head);
            break;

        case 3:
            printf("Enter item to be added at the start: ");
            scanf("%d", &item);
            head = addHead(item, head);
            printList(head);
            break;

        case 4:
            printf("Enter item to be added: ");
            scanf("%d", &item);
            printf("Enter the value after which to insert: ");
            scanf("%d", &after);
            head = insertAfter(item, after, head);
            printList(head);
            break;

        case 5:
            printf("Enter item to be added: ");
            scanf("%d", &item);
            printf("Enter the value before which to insert: ");
            scanf("%d", &before);
            head = insertBefore(item, before, head);
            printList(head);
            break;

        case 6:
            printf("\nDeleting Head\n");
            head = deleteHead(head);
            printList(head);
            break;

        case 7:
            printf("\nDeleting End\n");
            head = deletLastNode(head);
            printList(head);
            break;

        case 8:
            printf("Enter the index to delete: ");
            scanf("%d", &item); // 'item' here is used to store the index
            head = deleteAtIndex(item, head);
            printList(head);
            break;

        case 10:
            freeList(head);
            printf("Exiting...\n");
            flag = false;
            break;

        default:
            printf("\n--- Invalid Choice ---\n");
        }
    }

    return 0;
}
