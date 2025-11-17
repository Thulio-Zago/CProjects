// Online C compiler to run C program online
#include <stdio.h>

int main() {
  int valor= 14;
  int *ponteiro;
  ponteiro = &valor;
  
  
  printf("endereço de valor %d\n", &valor);
  printf("vqalor da variavel valor %d\n", valor);
  printf("endereço de ponteiro %d\n", &ponteiro);
  printf("valor da variavel ponteiro %d\n", ponteiro);
  printf("valor da variavel valor pelo ponteiro %d\n", *ponteiro);
  
}