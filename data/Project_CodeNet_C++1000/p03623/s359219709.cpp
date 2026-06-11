#include <stdio.h>
 
int abs(int z){
	if(z<0){
		z*=(-1);
	}
	return z;
}
int main (){
    int x, a, b;
    scanf ("%d %d %d", &x, &a, &b);
    if(abs(x-a)<abs(x-b)){
    	printf("A\n");
	}else{
		printf("B\n");
	}
    
    return 0;
}