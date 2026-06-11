#include <stdio.h>


int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int difA = b - a;
	int difB = c - a;

if(difA < 0){
	difA *= -1;
}
if(difB < 0){
	difB *= -1;
}

if(difA > difB){
	printf("B");
}else{
	printf("A");
}



	return 0;
}