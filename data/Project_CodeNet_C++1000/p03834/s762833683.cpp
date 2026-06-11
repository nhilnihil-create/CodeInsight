#include <stdio.h>
#include <string.h>

int main(){
	char input[20];
	scanf("%s", input);
	int len=strlen(input);
	
	for(int i=0; i<len; i++){
		if(input[i]==','){
			input[i]=' ';
		}
	}
	printf("%s", input);
	
	
	return 0;
}