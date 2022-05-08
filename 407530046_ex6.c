#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//double linked-list
struct node{
    char name[20];
    struct node *left;
    struct node *right;
};

//input num(int) of nodes into a circular linklist and return the first node's pointer.
struct node *add_node(int num);
//traversal the linklist and kill the node which is not in the k steps.
void kill(struct node *first, int k, char *direction);
//remove the node from the linklist.
void delete_node(struct node *ptr);

int main()
{
    int num, k;
    char direction[20];
    struct node *first = NULL;

    scanf(" %d",&num);
    first = add_node(num);
    scanf(" %d %s", &k, direction);
    kill(first, k, direction);

    return 0;
}

struct node *add_node(int num)
{
    struct node *ptr = NULL, *first = NULL;
    for(int i = 0 ; i < num ; i++)
    {
        struct node *new_node = malloc(sizeof(struct node));
        if(i == 0 )
        {
            first = new_node;
            ptr = new_node;
        }
        ptr->right = new_node;
        first->left = new_node;

        new_node->left = ptr;
        new_node->right = first;
        scanf(" %s",new_node->name);

        ptr = new_node;
    }    
    return first;
}

void kill(struct node *first, int k, char *direction)
{
    int count = 0; //Counting how many steps have token
    struct node *ptr = first, *temp; //temp records the current node, ptr records the next one
    if(strcmp(direction,"CLOCKWISE") == 0) 
    {
        while(ptr->right != ptr)
        {
            count++;
            temp = ptr;
            ptr = ptr->right;
            if(count % (k+1) == 0)
            {
                delete_node(temp);
            }
        }
    }
    else if(strcmp(direction,"COUNTERCLOCKWISE") == 0) 
    {
        while(ptr->left != ptr) 
        {
            count++;
            temp = ptr;
            ptr = ptr->left;
            if(count % (k+1) == 0) 
            {
                delete_node(temp);
            }
        }
    }
    else 
    {
        return;
    }
    printf("%s SURVIVE\n", ptr->name);
    free(ptr);
}

void delete_node(struct node *ptr)
{
    (ptr->left)->right = ptr->right;
    (ptr->right)->left = ptr->left;
    printf("%s KILLED\n", ptr->name);
    free(ptr);    
}