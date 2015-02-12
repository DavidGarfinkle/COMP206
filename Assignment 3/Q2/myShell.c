#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main(){
  char* CMD1="set prompt";
  char* CMD2="quit";
  char* PROMPT;
  char* INITIAL_PROMPT="Super Shell!!";
  int INPUT_SIZE=256;
  char input[INPUT_SIZE];
  char lowerinput[INPUT_SIZE];
  int i;
  
  //Initialize prompt message
  PROMPT = (char*) malloc(INPUT_SIZE*sizeof(char));
  strcpy(PROMPT, INITIAL_PROMPT);
  
  //While loop continues until user enters 'quit'
  while(1){
    printf("%s ", PROMPT); //Display prompt
    fgets(input, INPUT_SIZE, stdin); //Get user input and conver it all to lowercase
    for(i=0; i<strlen(input); i++) lowerinput[i] = tolower(input[i]);
    lowerinput[10]='\0'; //truncate user input to first ten characters
    if(strcmp(lowerinput, CMD1) == 0){ //check if it's equal to 'set prompt'
      for (i=11; i<INPUT_SIZE; i++){ //If 'set prompt' then remove first 10 characters of input and reset PROMPT
        PROMPT[i-11]=input[i];
        if(input[i] == '\n'){ //remove \n from input
          PROMPT[i-11]='\0';
          break; //break from the for-loop which is rewriting the PROMPT string
        }
      }
      continue; //after successfully changing the prompt, continue loop & re-prompt user
    }
    
    lowerinput[4] = '\0'; //truncate user input to the first four characters
    if (strcmp(lowerinput,CMD2) == 0) break; //if it's 'quit', then quit the loop
    
    else system(input); //Else, it was not one of our two shell commands. execute it on the command line! :)
  }
}
