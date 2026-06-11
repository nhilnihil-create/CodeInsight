#include <stdio.h>
int main(void){
char s[25];
  int count;
  scanf("%s",s);
  for(count=11;count!=3;count--){
  s[count+1]=s[count];
  }
  s[4]=' ';
  s[13]='\0';
  printf("%s\n",s);
return 0;
}