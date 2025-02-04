#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int coeff;
    int degree;
    struct Node *next;
};

// Global Variables

struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *head3 = NULL;

struct Node *createNode(int coeff, int degree)
{

    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));

    if (!newItem)
    {
        printf("\nMemory Full\n");
        return NULL;
    }

    newItem->coeff = coeff;
    newItem->degree = degree;
    newItem->next = NULL;

    return newItem;
}

void createListOne()
{
    int choice = 1;
    int coeff;
    int degree;

    printf("\nEntering in List One\n");

    while (choice)
    {
        printf("\nEnter the Coefficient : ");
        scanf("%d", &coeff);
        printf("\nEnter the Degree : ");
        scanf("%d", &degree);

        struct Node *newItem = createNode(coeff, degree);

        if (!head1)
        {
            head1 = newItem;
        }
        else
        {

            struct Node *temp = head1;

            while (temp->next)
                temp = temp->next;

            temp->next = newItem;
        }

        printf("\n Enter Choice (do you wish to add more nodes [Press 1 to add more & Press 0 to exit ]):");
        scanf("%d", &choice);
    }
}

void createListTwo()
{
    int choice = 1;
    int coeff;
    int degree;

    printf("\nEntering in List Two\n");

    while (choice)
    {
        printf("\nEnter the Coefficient : ");
        scanf("%d", &coeff);
        printf("\nEnter the Degree : ");
        scanf("%d", &degree);

        struct Node *newItem = createNode(coeff, degree);

        if (!head2)
        {
            head2 = newItem;
        }
        else
        {

            struct Node *temp = head2;

            while (temp->next)
                temp = temp->next;

            temp->next = newItem;
        }

        printf("\n Enter Choice (do you wish to add more nodes [Press 1 to add more & Press 0 to exit ]):");
        scanf("%d", &choice);
    }
}


void add(){

    struct Node * p1 = head1;
    struct Node * p2 = head2;
    struct Node * p3 = head3;
    struct Node *newItem;

    while (p1 && p2)
    {
        if(p1->degree > p2->degree){
            newItem = createNode(p1->coeff, p1->degree);
            p1 = p1->next;
        }
        else if(p1->degree < p2->degree){
            newItem = createNode(p2->coeff,p2->degree);
            p2 = p2->next;
        }else{
            newItem = createNode(p1->coeff + p2->coeff,p1->degree);
            p1 = p1->next;
            p2 = p2->next;
        }

        if(!head3){
            head3 = newItem;
        }else{
            newItem->next = head3;
            head3 = newItem;
        }
    }

    struct Node * remainingListPtr = ( p1 ? p1 : p2 );

    while (remainingListPtr)
    {
        newItem = createNode(remainingListPtr->coeff,remainingListPtr->degree);
        remainingListPtr = remainingListPtr->next;
    }

}

void printList(struct Node *headOfList)
{
    struct Node *temp = headOfList;
    while (temp)
    {
        printf("%d ", temp->coeff);
        printf("x**%d + ", temp->degree);
        temp = temp->next;
    }
}

int main()
{

    createListOne();
    createListTwo();
    printf("\nPolynomial 1 :");
    printList(head1);
    printf("\nPolynomial 2 :");
    printList(head2);
    add();
    printf("\nPolynomial 3 :");
    printList(head3);
    return 0;
}