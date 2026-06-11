#include <stdio.h>

int main(void){
   char str[100001];
   int i,len=0;
   
   scanf("%100000s",str);
   
   for(i=0;str[i]!='\0';i++){
       len++;
   }
   
   for(i=0;i<len-1;i++){
       if(str[i] == str[i+1]){
           printf("%d %d\n",i+1,i+2);
           return 0;
       }
   }
   
   for(i=0;i<len-2;i++){
       if(str[i] == str[i+2]){
           printf("%d %d\n",i+1,i+3);
           return 0;
       }
   }
   
   printf("-1 -1\n");
   return 0;
}
