#include <stdio.h>
#include <string.h>

int main(){
	int S, A, B;
	scanf ("%d %d %d", &S, &A, &B);
	int SA= A-S;
	int SB= B-S;
	(SA<=0)? (SA*=-1) : (SA*=1);
	(SB<=0)? (SB*=-1) : (SB*=1);
	(SA>SB)? (printf("B\n")) : (printf("A\n"));
return 0;
}
