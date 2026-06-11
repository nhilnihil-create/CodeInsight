#include <stdio.h>
#include<string.h>
 
int main(){
	char A[15], B[15], C[15];
	
	scanf("%s%s%s", &A,&B,&C); 
	
	if( A[strlen(A)-1]==B[0] && B[strlen(B)-1]==C[0]){
               printf("YES");
        }
	  else{
               printf("NO");
        }
	return 0;
}