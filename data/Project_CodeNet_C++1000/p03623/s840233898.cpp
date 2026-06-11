#include <stdio.h>
int main(){
	int A, B, x;
	scanf("%d %d %d", &x, &A, &B);
	
	int keA = 0;
	int keB = 0;
	
	keA += x - A;
	keB += x - B;
	
	if(keA < 0){
		keA *=-1;
	} 
	if(keB < 0){
		keB*=-1;
	}
	
	if(keA > keB) {
		printf("B\n");
	} 
	if(keB > keA) {
		printf("A\n");
	}
	
	return 0;
}