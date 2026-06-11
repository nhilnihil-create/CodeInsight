#include<stdio.h>
int main(){
	
char input[25];
	
scanf("%s",input);
	for(int i = 0; input[i] != '\0'; i++){
		if(input[i] >= 'a' && input[i] <= 'z'){
			printf("%c", input[i]);
		}
		else{
			printf(" ");
		}
	}
    return 0;
}
