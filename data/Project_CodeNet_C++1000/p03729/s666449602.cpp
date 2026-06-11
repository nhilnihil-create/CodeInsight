#include <stdio.h>
#include <string.h>

int main(void){
    // Your code here!
    char str[3][11];
    
    scanf("%10s%10s%10s",str[0],str[1],str[2]);
    
    if(str[0][strlen(str[0])-1] == str[1][0]){
        if(str[1][strlen(str[1])-1] == str[2][0]){
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");
    
}
