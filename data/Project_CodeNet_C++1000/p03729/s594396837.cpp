#include<stdio.h>
#include<string.h>
int main(){
	char input[3][30];
	int panjang[3];
	for(int i=0; i<3;i++){
	scanf("%s", input[i]);
	panjang[i]=strlen(input[i]);
	}
	
	if(input[0][panjang[0]-1]==input[1][0] &&input[1][panjang[1]-1]==input[2][0] ){
		puts("YES");
	}
	else{
		puts("NO");
	}
	
	return 0;
}