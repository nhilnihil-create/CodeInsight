#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll H,W,h,w,ans[505][505],tot;

int main()
{
	cin>>H>>W>>h>>w;
	if(H%h==0&&W%w==0) return puts("No"),0;
	for(int i=h;i<=H;i+=h)
	{
		for(int j=w;j<=W;j+=w) ans[i][j]=-1000000000;
	}
	for(int i=1;i<=H;i+=h)
	{
		for(int j=1;j<=W;j+=w) ans[i][j]=999999999;
	}
	puts("Yes");
	rep(i,1,H)
	{
		rep(j,1,W) printf("%lld ",ans[i][j]); puts("");
	}
	return 0;
}