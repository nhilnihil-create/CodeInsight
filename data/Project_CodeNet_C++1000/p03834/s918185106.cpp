#include <stdio.h>
 
int main(){
  char S[25];
  scanf("%s",S);

  for(int i=0;i<19;i++){
    if(S[i]==','){
         printf(" ");
    }
    else{
         printf("%c",S[i]);
       }
    }
  printf("\n");
  return 0;
}