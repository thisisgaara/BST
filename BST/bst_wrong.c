#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int value;
    struct bst *left, *right, *parent;
}bst;

struct bst *head;


void insert_head(int value)
{
    struct bst *temp = (struct bst*) malloc(sizeof(bst));
    temp -> value = value;
    temp -> left = NULL;
    temp -> right = NULL;
    head = temp;
}
void insert_body(int value)
{
    struct bst *t = (struct bst *) malloc(sizeof(bst));
    t -> left = NULL;
    t -> right = NULL;
    struct bst *parent = NULL, *temp = head;
    while(temp != NULL)
    {
        if(value < temp -> value)
        {
            parent = temp;
            temp = temp -> left;
        }
        else if(value > temp -> value)
        {
            parent = temp;
            temp = temp -> right;
        }
        else if(temp -> value == value)
        {
            printf("Value is already present in Tree");
            break;
        }
    }
    //Check the parent for inserting at correct place
    if(value < parent -> value)
    {
        //Left insertion
        t -> value = value;
        t -> parent = parent;
        if(parent -> left != NULL)
            t -> left = parent -> left;
        if(parent -> right != NULL)
            t -> right = parent -> right;
        if(parent -> left == NULL && parent -> right == NULL)
        {
            t -> left = NULL;
            t -> right = NULL;
        }
        parent -> left = t;
    }
    else if(value > parent -> value)
    {
        //Left insertion
        t -> value = value;
        t -> parent = parent;
        if(parent -> left != NULL)
        {
            t -> left = parent -> left;
        }
        if(parent -> right != NULL)
        {
            t -> right = parent -> right;
        }
        if(parent -> left == NULL && parent -> right == NULL)
        {
            t -> left = NULL;
            t -> right = NULL;
        }
        parent -> right = t;
    }
}


void inorder(struct bst *temp)
{
    if(temp != NULL)
    {
        inorder(temp -> left);
        printf("%d ", temp -> value);
        inorder(temp -> right);
    }
}
void insert(int value)
{
    if (head == NULL)
    {
        insert_head(value);
    }
    else
    {
        insert_body(value);
    }
}
int main()
{
    insert(8);
    insert(3);
    insert(1);
    insert(6);
    insert(4);
    insert(7);
    insert(10);
    insert(14);
    insert(13);
    inorder(head);
    return 0;
}
