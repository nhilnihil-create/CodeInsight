#include<cstdio>
char c[5]="RYGB",s[510];
int main(){
	int H,W,d;
	scanf("%d%d%d",&H,&W,&d);
	for(int i=0;i<H;i++,puts(s))
		for(int j=0;j<W;j++)s[j]=c[(i+j)/d%2*2+(i+W-j)/d%2];
}