#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

struct word{
  char word[MAX_WORD_LEN];
  struct word *next;
};
 
//char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
struct word *line = NULL;

//ok
void clear_line(void)
{
  //line[0] = '\0';
  struct word *temp;
  line_len = 0;
  num_words = 0;
  while(line != NULL){
    temp = line;
    line = line->next;
    free(temp);
  }
}

void add_word(const char *word)
{
  if (num_words > 0) 
  {
    line_len++; //前面要在算一個空白的位置
  }

  struct word *new_word = malloc(sizeof(struct word)), *ptr;
  strcpy(new_word->word,word);
  new_word->next = NULL;
  
  if(line == NULL)
  {
    line = new_word;
  }
  else
  {
    for(ptr = line ; ptr->next != NULL ; ptr = ptr->next);
    ptr->next = new_word;
  }

  line_len += strlen(word);
  num_words++;
}
 
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;
 
  extra_spaces = MAX_LINE_LEN - line_len;
  struct word *ptr;
  for(ptr = line;ptr->next != NULL;ptr = ptr->next){
    printf("%s",ptr->word);
    spaces_to_insert = extra_spaces / (num_words - 1);
    for (j = 1; j <= spaces_to_insert + 1; j++)
      putchar(' ');
    extra_spaces -= spaces_to_insert;
    num_words--;
  }
  printf("%s",ptr->word);
  putchar('\n');
}
 
//ok
void flush_line(void)
{
  if (line_len > 0){
    struct word *ptr;
    for(ptr = line;ptr->next != NULL;ptr = ptr->next){
      printf("%s ",ptr->word);
    }
    printf("%s",ptr->word);
    printf("\n");
  }
    //puts(line);
}
