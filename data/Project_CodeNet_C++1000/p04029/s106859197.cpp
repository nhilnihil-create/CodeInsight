#include <stdio.h>

int main (){
	int n,i,out=0;
	
	scanf ("%d",&n);
	
	for (i=1; i<=n; i++){
		out+=i;
	}
	printf ("%d", out);
	return 0;
}