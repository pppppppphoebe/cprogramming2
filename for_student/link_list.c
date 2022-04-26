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
	struct node *ptr;
	for(ptr = HEAD ; ptr != NULL && ptr->id != ID ; ptr = ptr->next );

	if(ptr != NULL){
		struct node *new_node = malloc(sizeof(struct node));
		new_node->id = node_id;
		strcpy(new_node->name, Name);
		new_node->next = ptr->next ;
		ptr->next = new_node;
	}else{
		printf("INVALID OPERATION\n");
	}
}

void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

	struct node *prev, *cur;
	for(cur = HEAD, prev = NULL;
		cur != NULL && strcmp(cur->name,Name) != 0 ;
		prev = cur, cur = cur->next);

	if(cur == NULL){
		printf("INVALID OPERATION\n");
	}
	else if(prev == NULL){
		HEAD = HEAD->next ;
		free(cur);
	}
	else{
		prev->next = cur->next;
		free(cur);
	}
}

void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
	struct node *p1,*prev_p1,*p2,*prev_p2,*temp;
	for(p1 = HEAD, prev_p1 = NULL ;
		p1 != NULL && strcmp(p1->name,Name1) != 0 && strcmp(p1->name,Name2) != 0;
		prev_p1 = p1, p1 = p1->next);
	
	if(p1 == NULL){
		printf("INVALID OPERATION\n"); 
		return;
	}

	for(p2 = p1->next, prev_p2 = p1 ;
		p2 != NULL && (strcmp(p2->name,p1->name) == 0 || (strcmp(p2->name,Name1) != 0 && strcmp(p2->name,Name2) != 0));
		prev_p2 = p2, p2 = p2->next);

	if(p2 == NULL){
		printf("INVALID OPERATION\n"); 
		return;
	}

	if(prev_p1 == NULL && prev_p2 == p1){
		p1->next = p2->next;
		p2->next = p1;
	}
	else if(prev_p1 == NULL && prev_p2 != p1){
		temp = p1->next;
		p1->next = p2->next;
		prev_p2->next = p1;
		p2->next = temp;
	}
	else if(prev_p2 == p1){
		p1->next = p2->next;
		prev_p1->next = p2;
		p2->next = p1;
	}else{
		prev_p2->next = p1;
		prev_p1->next = p2;
		temp = p2->next;
		p2->next = p1->next;
		p1->next = temp;		
	}
}

void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
	struct node *ptr;
	for(ptr = HEAD ; ptr != NULL && strcmp(ptr->name,Name) != 0 ; ptr = ptr->next );
	if(ptr != NULL){
		printf("%d\n",ptr->id);
	}else{
		printf("INVALID OPERATION\n");
	}
}

void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
	struct node *ptr;
	for(ptr = HEAD ; ptr != NULL && ptr->id != ID ; ptr = ptr->next );
	if(ptr != NULL){
		printf("%s\n",ptr->name);
	}else{
		printf("INVALID OPERATION\n");
	}
}

void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
	struct node *ptr;
	for(ptr = HEAD ; ptr != NULL ; ptr = ptr->next ){
		printf("%d %s\n",ptr->id,ptr->name);
	}
}

