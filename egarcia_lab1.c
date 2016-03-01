#include "egarcia_argtok.h"

int main(){
  char string[256]; 
  printf("$ ");
  scanf("%[^\n]%*c", string);
  char** tokens = argtok(string);
  print(tokens);
  return 0;
}
