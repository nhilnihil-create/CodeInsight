#include <stdio.h>
#include <string.h>

int main()
{ 
    
    char x[255];
    scanf("%s",x);
    int a= strlen(x);  
    for(int i=0;i<a;i++){
        if(x[i]==',')
        printf(" ",x[i]);
        else{
        printf("%c",x[i]);
		}
    }   
    return 0;
}

