#include <stdio.h>

int main() {
	
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	
	int aa;
	if(a>=x){
		aa=a-x;
	}
	else{
		aa=x-a;
	}

	int bb;
	if(b>=x){
		bb=b-x;
	}
	else{
		bb=x-b;
	}
	
	if(aa<bb){
		printf("A\n");
	}
	else{
		printf("B\n");
	}

    return 0;
}
