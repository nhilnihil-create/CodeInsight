#include <stdio.h>
int main(void){
    int a, b, w;
    scanf("%d%d%d", &w, &a, &b);
   	if(b > a + w){
   		printf("%d", b - (a + w));
   	}else if(a > b + w){
   		printf("%d", a - (b + w));
   	}else{
   	  	printf("0");  
   	}
   

}
