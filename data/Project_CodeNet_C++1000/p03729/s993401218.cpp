#include <stdio.h>
#include <string.h>
 
int main() {
	char A[255], B[255], C[255];
	scanf("%s %s %s", &A, &B, &C);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int lenC = strlen(C);
	
	if(A[lenA - 1] == B[0] && B[lenB - 1] == C[0]){
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}