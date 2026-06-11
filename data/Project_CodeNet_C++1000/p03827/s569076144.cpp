#include <stdio.h>
#include <string.h>

int main(){
	int a;
	scanf("%d", &a);
	
	int x = 0;
	int jml = 0;
	
	char array[100];
	scanf("%s", array);
	
	int arraylen = strlen(array);
	
	for(int i = 0; i < arraylen; i++){
		if(array[i] == 'I'){
			jml++;
		}
		else if(array[i] == 'D'){
			jml--;
		}
		if(x < jml){
			x = jml;
		}
	}
	printf("%d\n", x);
	return 0;
}