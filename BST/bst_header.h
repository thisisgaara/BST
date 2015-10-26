#include "bst.h"
extern struct bst* head;

struct bst* minimum(struct bst *head)
{
    struct bst* temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> left;
    }
    return temp;
}

struct bst* maximum(struct bst *head)
{
    struct bst* temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> right;
    }
    return temp;
}

struct bst* successor(struct bst *x)
{
    if(x -> right != NULL)
        return minimum(x -> right);
    struct bst *y = x  -> parent;
    while(y != NULL && y -> right == x)
    {
        x = y;
        y = y -> parent;
    }
    return y;
}

struct bst *transplant(struct bst **head, struct bst* u, struct bst* v)
{
    if(u -> parent == NULL)
       *head = v;
    else if(u -> parent -> left == u)
        u -> parent -> left = v;
    else if(u -> parent -> right == u)
        u -> parent -> right = v;
    if(v != NULL)
        v -> parent = u -> parent;
    return v;
}

struct bst * search(struct bst *head, int value)
{
    while(head != NULL)
    {
        if(value < head -> value )
            head = head -> left;
        else if(value > head -> value)
            head = head -> right;
        else if(value == head -> value)
            return head;
    }
    return NULL;
}

struct bst * deletion(struct bst *head, int value)
{
    struct bst *z = search(head, value);
    struct bst *y, *r;
    if(z != NULL)
    {
        if(z -> left == NULL) //only right child is present
        {
            transplant(&head, z, z -> right);

        }
        else if(z -> right == NULL) //Only left child is present
        {
            transplant(&head, z, z -> left);
        }
        else if(z -> right == NULL && z -> left == NULL)
        {
            transplant (&head, z, NULL);
        }
        else //Both the child are present
        {
            y = successor(z);
            if(y -> parent != z)
            {
                r = transplant(&head, y, y -> right);
                y -> right = z -> right;
                y -> right -> parent = y;
            }
            y = transplant(&head, z, y);
            y -> left = z -> left;
            y -> left -> parent = y;

        }
    return head;
    }
    else
        printf("Node not found ERROR\n");
}

/*
int main()
{
    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);
    inorder(head);
    printf ("Maximum value is %d \n", maximum(head) -> value);
    printf("\n");
    printf("The successor is %d ", successor(search(head, 40)) -> value);
    printf("Deleting 20\n");
    head = deletion(head, 20);
    printf("\n");
    printf("Deleting 30\n");
    head = deletion(head, 30);
    printf("Deleting 50\n");
    head = deletion(head, 50);
    inorder(head);
    return 0;
}
*/
