#include <stdio.h>

int main(){
	int him, A, B;
	scanf("%d %d %d", &him, &A, &B);
	int jwb1, jwb2;
	
	if(him - A < 0){
		jwb1 = (him - A) * -1;
	}else if(him - A >= 0){
		jwb1 = him - A;
	}
	
	if(him - B < 0){
		jwb2 = (him - B) * -1;
	}else if (him - B >= 0){
		jwb2 = him - B;
	}
	
	if(jwb1 < jwb2){
		printf("A\n");
	} else {
		printf("B\n");
	}
	return 0;
}