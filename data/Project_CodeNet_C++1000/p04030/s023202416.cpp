#include <stdio.h>
#include <string.h>

int main(){
    char str[11];
    scanf("%s", str);
    int len = strlen(str);
    char stro[11];
    int k = 0;
    for(int i = 0; i<len; i++){
        if(str[i] == 'B'){
        	if(i < len-1){
        		if(k>0){
            		k--;
        		}
            }
            else{
            	k--;
            	str[k] = '\b';
            }
        }
        else{
            stro[k] = str[i];
            k++;
        }
    }
    stro[k] = '\0';
    printf("%s\n", stro);
    
    return 0;
}