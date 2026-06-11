#include<stdio.h>
int main (){
	char str[19];
	scanf("%s", str);
	for(int i = 0; i < 19 ; i++){
		if(str[i] == ','){
			printf(" ");
		}
		else{
			printf("%c", str[i]);	
		}
	}

	return 0;
}