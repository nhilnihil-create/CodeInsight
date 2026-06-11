#include <stdio.h>

int main (){
	char a[100];
	scanf("%[^\n]", a);
	
	for ( int i = 0; a[i] != ','; i++ ){
		printf("%c", a[i]);
	}
	printf(" ");
	
	for ( int j = 6; a[j] != ','; j++ ){
		printf("%c", a[j]);
	}
	printf(" ");
	
	for ( int k = 14; a[k] != '\0'; k++ ){
		printf("%c", a[k]);
	}
	
	return 0;
}