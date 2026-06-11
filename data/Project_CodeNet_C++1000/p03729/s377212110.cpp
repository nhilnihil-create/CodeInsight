#include <stdio.h>
#include <string.h>
int main (){
	char kataA[11];
	char kataB[11];
	char kataC[11];
	
	scanf("%s %s %s", &kataA, &kataB, &kataC);
	
	int panjangA = strlen (kataA);
	int panjangB = strlen(kataB);
	
	if(kataA[panjangA-1] == kataB[0] && kataB[panjangB-1] == kataC[0]){
		puts("YES");
	}
	else{
		puts("NO");
	}
	
	return 0;
}