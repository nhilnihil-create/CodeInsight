#include <stdio.h>

int main (){
	char kalimat[20];
	scanf("%[^\n]", &kalimat);
	
	for (int i=0; i < 19 ; i++){
		if(kalimat[i] == ','){
		kalimat[i] = ' ';
		}
		}
	printf("%s", kalimat);
	
	
	return 0;
}