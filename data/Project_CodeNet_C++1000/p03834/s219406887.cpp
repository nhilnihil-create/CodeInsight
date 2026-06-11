#include <stdio.h>
int main(){
	char kata [25];
	scanf ("%[^\n]", kata);
	for (int i= 0; kata[i]!='\0';i++){
		if (kata[i]!=','){
			printf ("%c", kata[i]);	
		}else{
			printf (" ");
		}
	}
puts("");
	return 0;
}