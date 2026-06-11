#include <stdio.h>
int main(){
	int x, tokoA, tokoB, o, p;
	scanf("%d %d %d", &x, &tokoA, &tokoB);
	o= tokoA - x;
	p= tokoB - x;
	if(o<0){
		o=o*(-1);
	} 
	if(p<0){
		p=p*(-1);
	}
	if(o>p){
		printf("B\n");
	}else if (o<p){
		printf("A\n");
	}
	return 0;
}
