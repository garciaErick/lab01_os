/**
  * @author Erick Garcia egarcia87@miners.utep.edu
  * @desc This class will get an input from the user
  *   and tokenize it
  * @required egarcia_argtok.h
*/
#include "egarcia_argtok.h"

/**Func argtok 
 * @desc  Tokenize a string into a **char of *char
 * @param  c      = string we want to tokenize 
 * @return tokens = the tokenized string
 */
char** argtok(char* c){
  char **tokens; //Create our array of char* pointing to char*
  int no_of_tokens = count_tokens(c); //Counting our tokens 
  tokens    = (char**)calloc(no_of_tokens + 1, sizeof(char*));  //Add one for the '\0'
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
  return tokens;
}

/** func strcopy
  * @desc  Implementation of strcopy from source to destination
  * @param source       = complete source string from user
  * @param destination  = is our destination char*
  * @param index        = the index of the word we want to tokenize
  * @param size         = the size of the word we want to tokenize
  * @return destination = the copy of our source string
*/
char* strcopy(char* source, char* destination, int index, int size){
  // Allocate memmory for the size of the string we are going to copy 
  destination = (char*)malloc(size * (sizeof(char)));
  int i_source = index;   // Keep track of where we are in the source string
  int i_dest = 0; // Keep track of where we are in the dest string
  int max = (i_source + size); //Copying only a word from the source string
  for(i_source = index; i_source < max; i_source++, i_dest++){
    destination[i_dest] = source[i_source];
  }
  destination[size] = '\0'; //Setting the last index of our destination to '\0'
  return destination;
}

/** func    count_tokens
  * @desc   Count the number of tokens in a string  
  * @param  c     = string we want to count tokens from
  * @return count = number of tokens counting space and '\0' 
 */
int count_tokens(char* c){
  int i; 
  int count = 0;
  for(i = 0; c[i] != '\0'; i++){
    if(c[i] == ' '){
      count++;
    }
  }
  /* char **r = (char**)calloc(count + 2, sizeof(char*)); */
  return count + 2;
}

/* Print all of the tokens (words) in the char** */ 
void print(char** tokens){
  int i, j;
  for(i = 0; tokens[i] != NULL; i++){      //If null we are done
    for(j = 0; tokens[i][j] != '\0'; j++){ //If '\0' skip a line
      printf("%c", tokens[i][j]);
    }
    printf("\n");
  }
}

/** func   freeMemory
 * @desc   Since we are using malloc/calloc we have to free memory
 * from the heap
 * @param  tokens = **char that we will free
 */
void freeMemory(char** tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++){      //If null we are done
    free(tokens[i]);
  }
  free(tokens);
}
