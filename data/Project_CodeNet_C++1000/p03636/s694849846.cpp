#include <stdio.h>

int main(void){
  char input[101] = {0};
  scanf("%s",input);
  printf("%c",input[0]);
  for (int i=1;i<101;i++){
    if (input[i] == 0){
      printf("%d",i-2);
      printf("%c\n",input[i-1]);
      break;
    }
  }
  return 0;
}