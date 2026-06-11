#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	
	char letter[n];
	int isiLetter[n] = {0};
	int x = 0;
	for(int i = 0; i < n; i++){
		scanf("%c", &letter[i]);
		
		if(letter[i] == 'I'){
			isiLetter[i+1] = ++x;
		}
		else{
			isiLetter[i+1] = --x;
		}
	}
	getchar();
	
	int Max = isiLetter[0];	
	for(int i = 1; i <= n; i++){
		if(Max < isiLetter[i]){
			Max = isiLetter[i];
		}
	}
	
	printf("%d\n", Max);
	
	return 0;
}