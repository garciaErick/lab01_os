#include "egarcia_argtok.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  user(); //Ask for user input
  return 0;
}

char** argtok(char* c){
  char **tokens; //Create our array of char* pointing to char*
  tokens    = count_tokens(c); //Counting our tokens and allocating memory
  int count = 0;
  int index = 0;
  int i     = 0;
  /* Allocate memmory for each char* (word) and allocating the values */
  for(i = 0; c[i] != '\0'; i++){
    if(c[i] == ' '){         //Tokenize if there is an empty space
      tokens[index] = strcopy(c, tokens[index], i - count, count + 1);
      count         = -1;
      index++;
    }
    else if(c[i+1] == '\0'){ //Tokenize if there is an end of line character
      tokens[index] = strcopy(c, tokens[index], i - count, count + 2);
      count         = -1;
      index++;
    }
    count++;
  }
  /* Print our tokenized string */
  print(tokens);
  return tokens;
}

/* Copies a word of specified index and size from our source string into a destination */
char* strcopy(char* source, char* destination, int index, int size){
  // Allocate memmory for the size of the string we are going to copy 
  destination = malloc(sizeof(char) * (size));
  int i_source;   // Keep track of where we are in the source string
  int i_dest = 0; // Keep track of where we are in the dest string
  int max = (i_source + size); //Copying only a word from the source string
  for(i_source = index; i_source < max; i_source++, i_dest++){
    destination[i_dest] = source[i_source];
  }
  destination[size] = '\0'; //Setting the last index of our destination to '\0'
  return destination;
}

/*
 Number of tokens = {
 number of spaces,
 one '\0', 
 one to set our last index to NULL}
*/
char** count_tokens(char* c){
  int i; 
  int count = 0;
  for(i = 0; c[i] != '\0'; i++){
    if(c[i] == ' '){
      count++;
    }
  }
  char **r = calloc(count + 2, sizeof(char*));
  return r;
}

void print(char** tokens){
  int i, j;
  for(i = 0; tokens[i] != NULL; i++){      //If null we are done
    for(j = 0; tokens[i][j] != '\0'; j++){ //If '\0' skip a line
      printf("%c", tokens[i][j]);
    }
    printf("\n");
  }
}

void user(){
  char* c = malloc(sizeof(char));
  printf("$ ");
  scanf("%[^\n]%*c", c);
  argtok(c);
}

