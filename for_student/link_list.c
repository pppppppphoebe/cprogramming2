#include "myDS.h"
#include "basic.h"
/*
struct node{
    char name[15];
	int id;
    struct node *next;
};*/

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"
	struct node *ptr = HEAD ;
	struct node *new_node = malloc(sizeof(struct node));
	new_node->id = node_id;
	strcpy(new_node->name, Name);
	new_node->next = NULL;

	while(ptr!=NULL){
		if(ptr->id == ID){
			new_node->next = ptr->next ;
			ptr->next = new_node;
			return;
		}
		ptr = ptr->next ;
	}
	printf("INVALID OPERATION\n");
	free(new_node);
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

	struct node *pre, *cur;
	for(cur = HEAD, pre = NULL;
	cur != NULL && strcmp(cur->name,Name ) ;
	pre = cur, cur = cur->next);

	if(cur == NULL){
		printf("INVALID OPERATION\n");
	}
	if(pre == NULL){
		HEAD = HEAD->next ;
	}else{
		
	}

}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
}

