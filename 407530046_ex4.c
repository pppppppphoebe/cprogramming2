#include <stdio.h>
#include <math.h>

typedef struct
{
    int cof; 
    int exp; 
}polynomial;


int main(){
    int n_terms, n_unknown;

    //enter the number of terms:
    scanf("%d", &n_terms );
    while(n_terms == 0){
        printf("The number must be greater than zero!\n");
        scanf("%d", &n_terms);
    }

    //enter each term with cof and exp
    polynomial p[n_terms];
    for(int i = 0 ; i < n_terms ; i++ ){
        scanf("%d %d", &p[i].cof , &p[i].exp );
    }

    //output the polynomial
    for(int i = 0 ; i < n_terms ; i++ ){
        printf("%dx^%d", p[i].cof , p[i].exp);
        if(i != n_terms-1) printf(" + ");
    }
    printf(" = \n");

    //enter the number of unknown x
    scanf("%d", &n_unknown);
    while(n_unknown == 0){
        printf("The number must be greater than zero!\n");
        scanf("%d", &n_unknown);
    }

    //enter the unknown number x
    int x , ans = 0;
    for(int i = 0 ; i < n_unknown ; ){
        scanf("%d", &x);
        if(x == 0)
        {
            printf("The number must be greater than zero!\n");
            continue;
        }

        for(int j = 0 ; j < n_terms ; j++)
        {
            ans += p[j].cof * (int)pow(x,p[j].exp);
        }
        printf("%d\n", ans);
        ans = 0;
        i++;
    }
    
    return 0;
}