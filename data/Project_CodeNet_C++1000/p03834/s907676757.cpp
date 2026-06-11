#include <stdio.h>

int main(){

	char kalimat[20];
	scanf("%s", &kalimat);
	kalimat[5]=' ';
	kalimat[13]=' ';
	
	printf("%s\n", kalimat);	

	return 0;
}

