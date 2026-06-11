#include<stdio.h>

int main(){
	char str[25];
	scanf("%[^\n]", str);
	
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == ','){
			
			str[i] = ' ';
		}
	}
	
	printf("%s\n", str);
	
	return 0;
}