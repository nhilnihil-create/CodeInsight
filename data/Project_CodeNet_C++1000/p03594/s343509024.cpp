#include<stdio.h>
int h,w,d;
char c[9]="RGBY";
int calc(int x){
	x %= (2*d);
	if(x < 0)x += 2*d;
	return x / d;
}
int main(){
	scanf("%d%d%d",&h,&w,&d);
	for(int i=0; i<h; i++,puts(""))
		for(int j=0; j<w; j++)
			putchar(c[calc(i+j)*2+calc(i-j)]);
	return 0;
}
