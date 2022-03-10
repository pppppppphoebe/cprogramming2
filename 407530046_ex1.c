#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define  STRING_MAX 	100
#define  ARTICLE_MAX 	4095
char* 	findstart	( char* str1, char* str2 );
char* 	print_word	( char* str1, char* found, char* str2, int len );
char* 	stristr		( char* str1, char* str2 );
int 	check_str	( char* str1 );

int main(){
	char str[STRING_MAX+1],*str1,*str2;
	char article[ARTICLE_MAX+1],*found,*temp;
	int len;//length of str1
	fgets(str, STRING_MAX, stdin);
	str[strlen(str)-1]='\0';

	char *parameter,*other_parameter;

	str1 = strtok(str," \n\0");
	if((str2 = strtok(NULL," \n\0"))==NULL){
		//has less then 2 string input
		printf("The input format: string1 string2 [parameter]");
	}
	else if((parameter = strtok(NULL," \n\0")) != NULL && strcmp(parameter, "-i") != 0){
		//has a parameter after strings and it is not "-i"
		printf("The input format: string1 string2 [parameter]");
	}
	else if(!check_str(str1) || !check_str(str2)){
		//str1 or str2 is include other some symbol
		printf("The input format: string1 string2 [parameter]");
	}
	else if((other_parameter = strtok(NULL, " \n\0"))!=NULL){
		//there is more than one parameter
		printf("The input format: string1 string2 [parameter]");
	}
	else if(parameter == NULL) {
		//case sensitive
		len = strlen(str1);
		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
			found = strstr(article,str1); 
			temp = found; 
			while(found != NULL){
				temp = findstart(temp,article);
				temp = print_word(temp,found,str2,len);
				found = temp; // get rest uncompared article.
				found = strstr(found,str1);
				temp = found;
			}
		}
	}
	else if(strcmp(parameter,"-i") == 0) {
		//case insesitive 
		len = strlen(str1);
		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
			found = stristr(article,str1);
			temp = found;
			while(found != 0){
				temp = findstart(temp,article);
				temp = print_word(temp,found,str2,len);
				found = temp; // get rest uncompared article.
				found = stristr(found,str1);
				temp = found;
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
		if(!isalnum(*(p+i)) && *(p+i) != '-') return 0;
	}
	return 1;
}

//To print the word found in article
char* print_word( char* start, char* found, char* str2, int len ) 
{
	char* p = start; //p is the pointer run through the word.
	    while(isalnum(*p) || *p == '-'){
		if(p == found){
			//if p is point to where to change. print str2 replace str1 in this word.
			printf("%s",str2);
			p = p + len; //jump after the address should be replaced.
		}else{
			printf("%c",*p);
			p++;
		}
	}
    printf("\n");
    return p;
}

//To find the address can start print the word
char* findstart( char* str1, char* str2 )
{
    while(str1 != str2){
		if(isalnum(*(str1-1)) || *(str1-1) == '-'){
			str1--;
		}
        else break;
    }
    return str1;   
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