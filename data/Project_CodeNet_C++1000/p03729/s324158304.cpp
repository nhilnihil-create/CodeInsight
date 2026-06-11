#include <stdio.h>
#include <string.h>
int main (){

	char A [100], B [100], C [100];
	A [100]= 'a' - 'z';
	B [100]= 'a' - 'z';
	C [100]= 'a' - 'z';
	
	scanf ("%s %s %s", &A, &B, &C);

	if (A [strlen (A) - 1 ] == B[0] && B [strlen (B) - 1] == C[0]) {
		printf ("YES\n");
		
	}
	else {
		printf ("NO\n");
	}	
	return 0;
}