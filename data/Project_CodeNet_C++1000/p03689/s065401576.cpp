#include<bits/stdc++.h>
const int N=505;
int H,W,h,w,i,j,a[N][N],s;
int main(){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	for(i=0;i<H;++i)for(j=0;j<W;++j)s+=a[i][j]=i%h==h-1 && j%w==w-1?-h*w-(1<<20):
		(i%h==0 && j%w==0?h*w+(1<<20)-1:0);
	if(s<0){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(i=0;i<H;++i)for(j=0;j<W;++j)printf("%d%c",a[i][j],"\n "[j<W-1]);
	return 0;
}