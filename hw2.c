#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define NAME_LENGTH 50

struct course{
    char name[NAME_LENGTH];
    struct course *next;
    struct course *prior;
};

struct id{
    int id,next,prior;
    struct course *ptr;
};

int main(){
    int n;
    scanf("%d",&n);

    //new a header for linklist
    struct id id[n];

    for(int i = 0; i < n; i++){
        struct course *new_node = malloc(sizeof(struct course));
        scanf("%d %d %d %s", &id[i].id, &id[i].next, &id[i].prior, new_node->name);
        id[i].ptr = new_node;        
        new_node->next = NULL;
        new_node->prior = NULL;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(id[i].id == id[j].next){
                id[j].ptr->next = id[i].ptr;
            }
            if(id[i].id == id[j].prior){
                id[j].ptr->prior = id[i].ptr;
            }
        } 
    }
    
    struct course *first = id[0].ptr;
    char c;
    do{
        printf("Current Course: %s\n",first->name);
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c",&c);
        if((unsigned)c == (unsigned)'n'){
            
            if(first->next == NULL){
                printf("There is no next course.\n");
            }else{
                first = first->next;
            }
        }
        if((unsigned)c == (unsigned)'p'){
            if(first->prior == NULL){
                printf("There is no previous course.\n");
            }else{
                first = first->prior;
            }
        }
    }while((unsigned)c != (unsigned)'q');

    return 0;
}

