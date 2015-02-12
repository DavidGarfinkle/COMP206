#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define FRENCH
#define ENGLISH

typedef struct NODE{
  char* string;
  struct NODE* next;
} node;

void printNodes(node* toPrint){
    if(toPrint->string == NULL) return;
    printf("%s ", toPrint->string);
    if(toPrint->next != NULL) printNodes(toPrint->next);
}

void main(int argc, char* argv[]){
  int MAX_SIZE = 256;
  int i;
  const char* TERMINATE = "***END***";
  char word[MAX_SIZE];
  char input[MAX_SIZE];
  char c;
  node* head;
  node* lp;
  
  #ifdef FRENCH
    printf("Bienvenue a le programme de stockage de chaine infinie\n");
    printf("Si il vous plait, entrer un seul mot\n")
  #endif
  #ifdef ENGLISH
    printf("Welcome to the infinite string storage program.\n");
    printf("Please input a single word.\n");
  #endif

  head = (node*) malloc(sizeof(node));
  head->next = NULL;
  fgets(input, MAX_SIZE, stdin);
  sscanf(input, "%s", word);
  if (strcmp(word, TERMINATE) == 0) return;
  head->string = (char*) malloc(MAX_SIZE*sizeof(char));
  strcpy(head->string,word);
  
  lp = head;
  while(1){
    lp->next = (node*) malloc(sizeof(node));
    lp=lp->next;
    
    #ifdef FRENCH
    printf("Si il vous plait, entrer un seul mot\n")
    #endif
    #ifdef ENGLISH
    printf("Please input a single word.\n");
    #endif
    
    fgets(input, MAX_SIZE, stdin);
    sscanf(input, "%s", word);
    
    if (strcmp(word,TERMINATE) == 0) break;
    lp->string = (char*) malloc(MAX_SIZE*sizeof(char));
    strcpy(lp->string,word);
    lp->next=NULL;
  }
  printNodes(head);
  printf("\n");
}
