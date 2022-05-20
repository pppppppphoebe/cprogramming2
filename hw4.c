#include <stdio.h>
unsigned short swap_bytes(unsigned short i);
int main(){
    unsigned short num;
    //printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx",&num);
    num = swap_bytes(num);
    printf("%hx\n",num);
    return 0;
}
unsigned short swap_bytes(unsigned short i){
    //16bits
    unsigned short n1, n2;
    n1 = (i & 0x00ff) << 8;
    n2 = (i & 0xff00) >> 8;
    i = n1 + n2 ;
    return i;

}