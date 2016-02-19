#ifndef EGARCIA_ARGTOK_H_ 
#define EGARCIA_ARGTOK_H_
#include <stdio.h>
#include <stdlib.h>

/* argtok():       Argument tokenizer                */
/* strcopy():      My own implementation of strcopy  */
/* count_tokens(): Counting Number of Tokens (Words) */
/* print():        Printing tokenized string         */
/* user():         Get User input                    */

char** argtok(char*);
char*  strcopy(char* source, char* destination, int index, int size);
char** count_tokens(char* c);
void   print(char**);
void   user();

#endif //EGARCIA_ARGTOK_H_ 

