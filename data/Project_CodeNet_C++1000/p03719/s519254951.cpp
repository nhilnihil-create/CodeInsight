#include<stdio.h>
int main(void)
{
	int i,a,b,c,w;
	scanf("%d %d %d",&a,&b,&c);
	w=0;
	for(i=a;i<=b;i++){
		if(i==c){
			w++;
		}
	}
	if(w==0){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}