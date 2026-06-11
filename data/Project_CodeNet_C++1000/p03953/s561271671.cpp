#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int c[maxn],a[maxn],to[maxn],ans[maxn],tmp[maxn],p[maxn],pos[maxn],K,now;
int n,m;
void solve(int y)
{
	for(;y;y>>=1)
	{
		if (y&1)
		{
			for (int i=1;i<=n;++i)p[i]=ans[to[i]];
			for (int i=1;i<=n;++i)ans[i]=p[i];
		}
		for (int i=1;i<=n;++i)p[i]=to[to[i]];
		for (int i=1;i<=n;++i)to[i]=p[i];
	}
	for(int i=1;i<=n;++i)p[i]=c[ans[i]];
	for(int i=1;i<=n;++i)c[i]=p[i];
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n;++i)cin>>pos[i],c[i]=pos[i]-pos[i-1],to[i]=ans[i]=i;
	scanf("%d%lld",&m,&K);
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=m;++i)
		swap(to[a[i]],to[a[i]+1]);
	solve(K);
	for (int i=1;i<=n;++i)
		c[i]+=c[i-1],cout<<c[i]<<".0 "<<endl;;
}
/*
这个1e18 明示矩阵加速/倍增 
fi表示第i只兔子的期望位置。
扫操作，每次操作还要扫一下上一只和下一只，然后才能转移
这 
pos[i]=pos[i-1]+pos[i+1]-pos[i]

草啊谁tm想得到差分啊？？？？
 */