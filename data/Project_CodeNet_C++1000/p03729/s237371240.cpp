#include <stdio.h>
#include <string.h>
 
int main(){
	int i, j;
	 char A[255], B[255], C[255];
	 scanf("%s %s %s", A, B, C);
	 
	 if (A[strlen(A)-1] == B[0] && B[strlen(B)-1] == C[0]){
	 	printf("YES\n");
	 } 
	 else {
	 	printf("NO\n");
	 }
	
	return 0;
}