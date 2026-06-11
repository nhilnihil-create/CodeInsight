#include<bits/stdc++.h>
using namespace std;
const int inf=1e9,N=520;
int H,W,h,w,dat,a[N][N];
int main(){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0)puts("No"),exit(0);
	dat=(inf-1)/(h*w-1);puts("Yes");
	for(int i=1;i<=H;i++,puts(""))
		for(int j=1;j<=W;j++)
			printf("%d ",i%h||j%w?dat:-inf);
	return 0;
}