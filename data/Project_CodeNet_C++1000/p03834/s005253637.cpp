#include <stdio.h>
#include <string.h>

int main(){
 char kata[19];
 scanf("%[^\n]", &kata);
 
 for(int i = 0; i<19; i++){
  if(kata[i]== ','){
   printf(" ");
  }
  else {
  printf("%c", kata[i]);
 }
}
 return 0;
}