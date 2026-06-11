#include <stdio.h>

int main()
{	 
	int a, b, f, cf; 
	
	scanf("%d%d", &a, &b);
	if(!a) f = 0;
	else if(a > 0) f = 1;
	else if(b < 0){
		cf = b - a;
		if(cf & 1) f = 1;
		else f = -1;
	}
	else f = 0;
	if(f == 1) puts("Positive");
	else if(!f) puts("Zero");
	else puts("Negative");
		
	return 0;
}