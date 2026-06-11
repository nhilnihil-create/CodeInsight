#include <string.h>
#include <stdio.h>
int main (){
	char input[101],temp;
	scanf ("%s",input);
	
	for (int i=0; i < strlen(input);i++){
		if (input[i]== ','){
			printf(" ");
		}
		else {
			printf("%c",input[i]);
		}
	}
	

	return 0;
}