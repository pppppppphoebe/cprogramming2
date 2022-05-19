#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_SIZE 30
#define ATTRIBUTE_SIZE 10

//table of attributes and their priority inorder is 0, 1, 2, 3, 4.
static char *table[] = { "WATER", "FIRE", "EARTH", "LIGHT", "DARK" };
enum attr { WATER , FIRE , EARTH , LIGHT , DARK };

struct pokemon {
    char name[NAME_SIZE];
    enum attr attribute;
    int  attack;
    int  hp;  
};

//change attribute(char *) to priority(enum attr: 0 ~ 4) and 0 is the highest.
enum attr ToEnum(char *attr);
//compare a->name and b->name (A < Z)
int  cmp_name(const void *a, const void *b);
//compare a->attribute's and b->attribute's priority 
int  cmp_attribute(const void *a, const void *b);
//compare attack wether b is bigger than a 
int  cmp_attack(const void *a, const void *b); 
//compare hp wether b is smaller than a 
int  cmp_hp(const void *a, const void *b);
//print all pokemon's info
void print_case(int n, struct pokemon *ptr);

int main()
{
    int  n,m;
    char query[10];
    char attribute[10];
    scanf("%d %d", &n, &m);


    struct pokemon *first = malloc(n*sizeof(struct pokemon));
    struct pokemon *ptr = first;

    for(int i = 1 ; i <= n ; i++)
    {
        scanf(" %s %s %d %d", ptr->name, attribute, &(ptr->attack), &(ptr->hp));
        ptr->attribute = ToEnum(attribute);
        ptr++;
    }  
    
    for(int i = 1 ; i <= m ; i++)
    {
        scanf(" %s", query);
        printf("Case #%d:\n", i);
        if( !strcmp(query, "NAME") )
        {
            qsort(first, n, sizeof(struct pokemon), cmp_name);
        }
        else if( !strcmp(query, "ATTRIBUTE") )
        {
            qsort(first, n, sizeof(struct pokemon), cmp_attribute);
        }
        else if( !strcmp(query, "ATTACK") )
        {
            qsort(first, n, sizeof(struct pokemon), cmp_attack);
        }
        else if( !strcmp(query, "HP") )
        {
            qsort(first, n, sizeof(struct pokemon), cmp_hp);
        }
        print_case(n, first);
    }
    return 0;
}

void print_case(int n, struct pokemon *ptr)
{
    for(int i = 1 ; i <= n ; i++)
    {
        printf("%s %s %d %d\n", ptr->name, table[ptr->attribute], ptr->attack, ptr->hp);
        ptr++;
    }
}

int cmp_name( const void *a, const void *b)
{
    return( strcmp(((struct pokemon *)a)->name, ((struct pokemon *)b)->name) );
}

int cmp_attribute(const void *a, const void *b)
{
    int n1 = ((struct pokemon *)a)->attribute;
    int n2 = ((struct pokemon *)b)->attribute;
    if(n1 == n2)
    {
        //when their priority is the same.
        return cmp_hp(a, b);
    }
    return n1 > n2;
}

int cmp_attack( const void *a, const void *b) 
{ 
    return ((struct pokemon *)a)->attack < ((struct pokemon *)b)->attack; 
}

int cmp_hp( const void *a, const void *b) 
{ 
    return ((struct pokemon *)a)->hp > ((struct pokemon *)b)->hp; 
}

enum attr ToEnum(char *attr)
{
    //enum attr { WATER , FIRE , EARTH , LIGHT , DARK };
    enum attr i;
    if( !strcmp(attr, "WATER") )
    {
        i = WATER;
    }
    else if( !strcmp(attr, "FIRE") )
    {
        i = FIRE;
    }
    else if( !strcmp(attr, "EARTH") )
    {
        i = EARTH;
    }
    else if( !strcmp(attr, "LIGHT") )
    {
        i = LIGHT;
    }
    else if( !strcmp(attr, "DARK") )
    {
        i = DARK;
    }
    else
    {
        printf("not matching\n");
        exit(0);
    }      
    return i;
}