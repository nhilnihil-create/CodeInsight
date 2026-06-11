#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll a[N],b[N],n,x,y,fst[N],nxt[N],to[N],l,fa[N];
void link(ll x,ll y)
{
	to[++l]=y;nxt[l]=fst[x];fst[x]=l;
	to[++l]=x;nxt[l]=fst[y];fst[y]=l;
}
void biu()
{
	puts("NO");
	exit(0);
}
void dfs(ll x)
{
	b[x]=(nxt[fst[x]]==0)?a[x]:a[x]*2;
	for (ll i=fst[x];i;i=nxt[i])
		if (to[i]!=fa[x])
		{
			fa[to[i]]=x;
			dfs(to[i]);
			b[x]-=b[to[i]];
			if (b[to[i]]>a[x]) biu();
		}
	if (b[x]<0||b[x]>a[x]) biu();
}
int main()
{
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (ll i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		link(x,y);
	}
	dfs(1);
	if (b[1])biu();
	puts("YES");
}