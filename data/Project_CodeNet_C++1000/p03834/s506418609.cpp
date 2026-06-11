#include <stdio.h>

int main (){
	char a[19];
	scanf("%[^\n]", &a);
	for (int i=0; a[i]!= '\0'; i++){
		if (a[i]==','){
			printf(" ");
		}
		else {
			printf("%c", a[i]);
		}
	}
	return 0;
}