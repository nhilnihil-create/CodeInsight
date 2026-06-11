#include<stdio.h>
#include<string.h>

#define SIZE 101





int main(void){
  int length;
  char message[SIZE];
  
  //fgets(message, SIZE, stdin);
  scanf("%s",message);
  
  length = strlen(message);
  
  printf("%c%d%c\n",message[0], length - 2, message[length-1]);
  
  return 0;
}
