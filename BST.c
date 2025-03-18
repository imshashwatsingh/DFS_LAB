#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

typedef struct Node* nodePtr;
nodePtr root=NULL;
nodePtr loc=NULL;
nodePtr ploc=NULL;


nodePtr createNode(int value){
    nodePtr ptr = (nodePtr) malloc(sizeof(struct Node));
    ptr->left=NULL;
    ptr->data=value;
    ptr->right=NULL;
    return ptr;
}

void search(int item){
    if(root==NULL){
        printf("Tree is empty.");
        loc=NULL;
        ploc=NULL;
        return;
    }
    loc=root;
    while(loc != NULL){
        if(loc->data == item){
            printf("Element Found!");
            return;
        }
        ploc=loc;
        if(loc->data > item){
            loc = loc->left;
        }else{
            loc = loc->right;
        }
    }
    printf("Element not found.");
}


void insert(int item){
    nodePtr ptr = createNode(item);
    if(root == NULL){
        root = ptr;
        return;
    }
    ploc = NULL;
    loc = root;
    while(loc != NULL){
        ploc = loc;
        if(item == loc->data){
            printf("Duplicate not allowed!!");
            free(ptr);
            return;
        }else if(item > loc->data){
            loc = loc->right;
        }else{
            loc = loc->left;
        }
    }
    if(item < ploc->data){
        ploc->left = ptr;
    }else{
        ploc->right = ptr;
    }
}

void inorder(nodePtr node){

    if(node != NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void delete(int key){
    if(root == NULL){
        printf("Tree empty!");
        return;
    }
    search(key);
    if (!loc)
    {
        printf("Element Not Found!!");
        return;
    }
    
    // single and no child
    if(loc->left == NULL || loc->right == NULL){
        nodePtr child = loc->left == NULL ? loc->right : loc->left;
        if(ploc->data < key){
            ploc->right = child;
        }else{
            ploc->left = child;
        }
        free(loc);
    }else{
        // Double child
        nodePtr succ = loc->right;
        while(succ->left != NULL){
            succ=succ->left;
        }
        loc->data = succ->data;
        delete(succ->data);
    }
}

int countLeaf(nodePtr root){
    if(root == NULL){
        return 0;
    }
    if(!root->left && !root->right) return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

void main(){
    int n=7;
    for(int i=0; i<n; i++){
        int item;
        printf("Enter Number %d: ", i+1);
        scanf("%d", &item);
        insert(item);
    }
    printf("\nInorder Traversal is: \n");
    inorder(root);
    printf("\n%d", countLeaf(root));
}