#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DEBUG 1
#define STRING_MAX 	100
#define ARTICLE_MAX 4095
//replace the symbols(not number, letter and dash) to space
#define SYMBOL_TO_SPACE(article) \
            for(int i=0;i<strlen(article);i++){\
                if(!isalnum(article[i]) && article[i]!='-') article[i]=' ';\
            }
#define CHECK_FOUND(word,found,str1,str2,len)\
            if(found != 0){\
                printf("\n");\
                print_word(word,found,str2,len);\
            }

void 	print_word	( char* str1, char* found, char* str2, int len );
char* 	stristr		( char* str1, char* str2 );
int 	check_str	( char* str1 );

int main(){
	char str[STRING_MAX+1],*str1,*str2;
	char article[ARTICLE_MAX+1],*found,*word;
    char *parameter,*other_parameter;
	int len;//length of str1

	fgets(str, STRING_MAX, stdin);
	str[strlen(str)-1]='\0';
	str1 = strtok(str," \r\n\0");

	if((str2 = strtok(NULL," \r\n\0"))==NULL){
		//has less then 2 string input
		printf("The input format: string1 string2 [parameter]\n");
	}
	else if((parameter = strtok(NULL," \r\n\0")) != NULL && strcmp(parameter, "-i") != 0){
		//has a parameter after strings and it is not "-i"
		printf("The input format: string1 string2 [parameter]\n");
	}
	else if(!check_str(str1) || !check_str(str2)){
		//str1 or str2 is include other some symbol
		printf("The input format: string1 string2 [parameter]\n");
	}
	else if((other_parameter = strtok(NULL, " \r\n\0"))!=NULL){
		//there is more than one parameter
		printf("The input format: string1 string2 [parameter]\n");
	}
	else if(parameter == NULL) {
		//case sensitive
        #if DEBUG
            printf("this is case 0");
        #endif
		len = strlen(str1);

		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
            SYMBOL_TO_SPACE(article);
            word = strtok(article, " ");
            /* walk through other words */
            while( word != NULL ) 
            {
                printf("\n");
                #if DEBUG
                    printf("the word is: %s", word);
                #endif
                found = strstr(word,str1);
                CHECK_FOUND(word,found,str1,str2,len);
                word = strtok(NULL, " ");
            }
		}
	}  
	else if(strcmp(parameter,"-i") == 0) {
		//case insesitive 
        #if DEBUG
            printf("this is case 1");
        #endif
        len = strlen(str1);

		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
            SYMBOL_TO_SPACE(article);
            word = strtok(article, " ");
            /* walk through other words */
            while( word != NULL) 
            {
                printf("\n");
                #if DEBUG
                    printf("the word is: %s", word);
                #endif
                found = stristr(word,str1);
                CHECK_FOUND(word,found,str1,str2,len);
                word = strtok(NULL, " ");
            }
		}
	}
	return 0;
}

//Check whether str has letter, number and '-' only
int check_str(char* str1){
	int len = strlen(str1);
	char* p=str1;
	for(int i=0;i<len;i++){
		if(isalnum(*(p+i)) || *(p+i)=='-'){}
        else return 0;
	}
	return 1;
}

//To print the word found in article
void print_word( char* start, char* found, char* str2, int len ) 
{
	char* p = start; //p is the pointer run through the word.
    while(*p!='\0'){
		if(p == found){
			//if p is point to where to change. print str2 replace str1 in this word.
			printf("%s",str2);
			p = p + len; //jump after the address should be replaced.
		}else{
			printf("%c",*p);
			p++;
		}
    }
}

//Similar to strstr() but for case insensitive
char* stristr( char* str1, char* str2 )
{
    const char* p1 = str1 ;
    const char* p2 = str2 ;
    //const char* r = *p2 == 0 ? str1 : 0 ;
	const char* r = 0; 

    while( *p1 != 0 && *p2 != 0 )
    {
        if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
        {
            if( r == 0 )
            {
                r = p1 ;
            }
            p2++ ;
        }
        else
        {
            p2 = str2 ;
            if( r != 0 )
            {
                p1 = r + 1 ;
            }
			if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
            {
                r = p1 ;
                p2++ ;
            }
            else
            {
                r = 0 ;
            }
        }
        p1++ ;
    }
    return *p2 == 0 ? (char*)r : 0 ;
}