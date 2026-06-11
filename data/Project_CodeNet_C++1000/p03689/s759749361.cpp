#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int K=500+5;

int main()
{
	//freopen("1.in","r",stdin);
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	if(H%h==0&&W%w==0)
	{
		puts("No");
		exit(0);
	}
	puts("Yes");
	int v=-(((h*w)-1)*K+1);
	rep(i,1,H)
	{
		rep(j,1,W)
		printf("%d ",(i%h==0&&j%w==0)?v:K);
		puts("");
	}
}