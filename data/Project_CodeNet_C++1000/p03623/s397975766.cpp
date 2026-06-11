#include<stdio.h>
int main(){
    
    int x, a, b;
    int diffa, diffb;
    scanf("%d%d%d", &x, &a, &b);
    diffa = x-a;
    if(diffa<0){
    	diffa *= -1;
	}
    diffb = x-b;
    if(diffb<0){
    	diffb *= -1;
	}
    if(diffa>diffb){
    	printf("B");
	} else {
		printf("A");
	}
    
    
    return 0;
}