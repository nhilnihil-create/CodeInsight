#include <stdio.h>

int main (){
	
	char s[25];
	scanf ("%[^\n]", &s);
	
	for (int i= 0; i < s[i]; i++  ) {
		if ( s[i] == ','){
			printf (" ");
		}
		else {
			printf ("%c", s[i]);
		}
	}
	
	
	puts ("");
	return 0;
}