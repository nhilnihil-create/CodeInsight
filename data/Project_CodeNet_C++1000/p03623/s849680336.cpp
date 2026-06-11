#include <stdio.h>

int main(){
	int x,a,b;
	scanf("%d %d %d",&x,&a,&b);
	int dis_a=x-a;
	int dis_b=x-b;
	if(dis_a<0){
		dis_a*=-1;
	}
	if(dis_b<0){
		dis_b*=-1;
	}
	if(dis_a>dis_b){
		printf("B");
	}
	else if (dis_a<dis_b){
		printf("A");
	}
	return 0;
}