#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+10;

int n,m,Ans[maxn],vis[maxn];

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int i,j,l,r,x;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		if (!l) {Ans[1]++; continue;}
		int last=m+1;
		for (x=1;x*x<=r;x++)
		{
			int u=(l+x-1)/x,v=r/x;
			if (u<=v)
			{
				if (v<last) Ans[u]++,Ans[v+1]--;
				else Ans[u]++,Ans[last]--;
				last=u;
				for (j=u;j<=v&&j*j<=r&&vis[j]!=i;j++) vis[j]=i;
			}
		}
		for (x=1;x*x<=r;x++)
		{
			int u=(l+x-1)/x,v=r/x;
			if (u<=v&&vis[x]!=i)
				vis[x]=i,Ans[x]++,Ans[x+1]--;
		}
	}
	for (i=1;i<=m;i++)
		Ans[i]+=Ans[i-1],printf("%d\n",Ans[i]);
}
