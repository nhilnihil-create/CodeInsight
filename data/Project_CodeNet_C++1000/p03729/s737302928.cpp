#include <stdio.h>
#include <string.h>
 
int main(){
	char A[11] ,B[11], C[11];
	scanf("%s %s %s", &A, &B, &C);
 
	int x = strlen(A), y = strlen(B);
	if(A[x-1] == B[0] && B[y-1] == C[0]){
		printf("YES \n");
	}else {
		printf("NO \n");
	}
	return 0;
}