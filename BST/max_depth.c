#include "bst_header.h"
extern struct bst *head;



int max_depth(struct bst *head)
{
    struct bst* temp = head;
    int val1, val2;
    //Assumption it is either got to be the maximum element depth on left subtree
    //or minimum on the right subtree. Let's see
    if(head == NULL)
        return 0;
    val1 = max_depth(head -> left);
    val2 = max_depth(head -> right);
    if(val1 > val2)
        return (val1 +1);
    return(val2 + 1);

}
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
    printf("\nMaximum depth %d", max_depth(head));

/*
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
*/
    return 0;
}
