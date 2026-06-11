#include <stdio.h>
#include <string.h>
 
int main(){
	
char str[20];
    
    scanf("%[^\n]", str);
    
  	for(int i = 0; i < 19; i++)
	{
    	
      if(str[i] == ','){
      	printf(" ");
        }else{
        printf("%c", str[i]);
        
      }
    }

}