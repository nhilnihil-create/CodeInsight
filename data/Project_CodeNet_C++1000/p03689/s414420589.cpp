#include<cstdio>
const int B=10000;
int H,W,h,w;
int main(){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0)puts("No");
	else{
		puts("Yes");
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
				printf("%d%c",H%h?i%h<h-1?B:-B*(h-1)-1:j%w<w-1?B:-B*(w-1)-1," \n"[j==W-1]);
	}
}