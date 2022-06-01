#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int size = n / 4;
    unsigned char access[size];
    //initalization
    for(int i = 0 ; i < size ; i++)
    {
        access[i] = 0;
    }
    
    int a,i,j; //a : input(login person), i : which char index, j : which place in access[i]
    while(scanf("%d",&a) != EOF)
    {
        i = a / 4;
        j = a % 4;
        
        //login amount is more than 3 times
        if((access[i] >> (j * 2)) % 4 == 3) //shift the corresponding 2 bits to the end and check if the last two bit is 3.
        {
            printf("GOOD BYE\n");
            continue;
        }
        
        //login amount is not more than 3 times
        access[i] = access[i] + ( 1 << ( j * 2 ) ); //add 1 to the corresponding bit
        printf("PASS\n");
    }
    return 0;
}