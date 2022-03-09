#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STRING_MAX 100
#define ARTICLE_MAX 4095
char* findstart( char* str1, const char* str2 );
char* print_word(char* str1, char* ret, const char* str2, int len);
char* stristr( const char* str1, const char* str2 );
int cheak_str(char* str1);

int main(){
	
	char str[STRING_MAX+1],*str1,*str2;
	char article[ARTICLE_MAX+1],*ret,*temp;
	int len;
	fgets(str,STRING_MAX,stdin);
	str[strlen(str)-1]='\0';

	char *p;

	str1 = strtok(str," \n\0");
	if((str2 = strtok(NULL," \n\0"))==NULL){
		printf("The input format: string1 string2 [parameter]");
	}
	else if((p = strtok(NULL," \n\0"))!=NULL && (strcmp(p,"-i")!=0)){
		printf("The input format: string1 string2 [parameter]");
	}
	else if(!cheak_str(str1) || !cheak_str(str2)){
		printf("The input format: string1 string2 [parameter]");
	}
	else if(p == NULL) {
		len = strlen(str1);
		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
			ret = strstr(article,str1);
			temp = ret;
			while(ret != NULL){
				temp = findstart(temp,article);
				temp = print_word(temp,ret,str2,len);
				ret = temp;
				ret = strstr(ret,str1);
				temp = ret;
			}
		}
	}
	else if(strcmp(p,"-i") == 0) { 
		len = strlen(str1);
		while(fgets(article,ARTICLE_MAX,stdin)!=NULL){
            article[strlen(article)-1]='\0';
			ret = stristr(article,str1);
			temp = ret;
			while(ret != 0){
				temp = findstart(temp,article);
				temp = print_word(temp,ret,str2,len);
				ret = temp;
				ret = stristr(ret,str1);
				temp = ret;
			}
		}
	}

	
	return 0;

}
int cheak_str(char* str1){
	int len = strlen(str1);
	char* p=str1;
	for(int i=0;i<len;i++){
		if(!isalnum(*(p+i)) && *(p+i) != '-') return 0;
	}
	return 1;
}
char* print_word( char* str1, char* ret, const char* str2, int len ) 
{
    while(isalnum(*str1) || *str1 == '-'){
		if(str1 == ret){
			printf("%s",str2);
			str1 = str1 + len;
		}else{
			printf("%c",*str1);
			str1++;
		}
	}
    printf("\n");
    return str1;
}

char* findstart( char* str1, const char* str2 )
{
    while(str1 != str2){
		if(isalnum(*(str1-1)) || *(str1-1) == '-'){
			str1--;
		}
        else break;
    }
    return str1;   
}

char* stristr( const char* str1, const char* str2 )
{
    const char* p1 = str1 ;
    const char* p2 = str2 ;
    const char* r = *p2 == 0 ? str1 : 0 ;

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