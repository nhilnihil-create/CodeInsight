#include <stdio.h>
#include <string.h>

int main(){
	char x[105];
	char y[105];
	char z[105];
	int a,b;
	scanf("%s %s %s", &x,&y,&z);
	a = strlen(x)-1;
	b = strlen(y)-1;
	if ( x[a]== y[0] && y[b]==z[0]){
		printf("YES\n");
	}	
	else{
		printf("NO\n");
	}
	return 0;
}