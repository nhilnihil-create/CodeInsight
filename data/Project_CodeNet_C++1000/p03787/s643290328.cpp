#include <bits/stdc++.h>
using namespace std;

int n,m,f[100010],dis[100010],siz[100010],a[100010],A,B,C;

void find(int x)
{
	if (f[x]!=x)  find(f[x]),dis[x]^=dis[f[x]],f[x]=f[f[x]];
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)  f[i]=i,siz[i]=1;
	for (int i=1,u,v;	i<=m; i++)
		{
			scanf("%d %d",&u,&v),find(u),find(v);
			if (f[u]!=f[v])
				siz[f[u]]+=siz[f[v]],a[f[u]]|=a[f[v]],dis[f[v]]=dis[v]^1,f[f[v]]=u;
			else  a[f[u]]|=dis[u]^dis[v]^1;
		}	
	for (int i=1; i<=n; i++)
		if (f[i]==i)  (siz[i]==1?A:a[i]?C:B)++;
	printf("%lld",1LL*A*A+2LL*A*(n-A)+2LL*B*(B+C)+1LL*C*C);
}

int main()
{
	work();
	return 0;
}
