#include <stdio.h>
#include <string.h>
int main(){
	
	char namaA[15];
	char namaB[15];
	char namaC[15];
	
	scanf("%s %s %s", &namaA,&namaB,&namaC);

	int panjangA = strlen(namaA) - 1;
	int panjangB = strlen(namaB) - 1;
	int panjangC = strlen(namaC) - 1;
	
	if(namaA[panjangA] == namaB[0] && namaB[panjangB] == namaC[0]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}