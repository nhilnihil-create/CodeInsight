#include <stdio.h>
#include <string.h>

int main(){
	char A[15], B[15], C[15];
	scanf("%s %s %s", &A, &B, &C);
	
	int lastCharA = strlen(A) - 1;
	int lastCharB = strlen(B) - 1;
	
	if(A[lastCharA] == B[0] && B[lastCharB] == C[0]){
		puts("YES");
	}
	else{
		puts("NO");
	}
	
	return 0;
}