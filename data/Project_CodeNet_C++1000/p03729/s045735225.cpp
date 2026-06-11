#include <stdio.h>
#include <string.h>

int main() {
	char A[15], B[15], C[15];
	int lenA, lenB;
	scanf("%s %s %s", A, B, C);
	
	lenA = strlen(A);
	lenB = strlen(B);
	if (A[lenA-1] == B[0] && B[lenB-1] == C[0]) {
		printf("YES\n");
	}
	else {
		puts("NO");
	}
	

	return 0;
}