#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=305;
int n,m,a[N][N],cnt[N],nw[N],vis[N];

void init()
{
	scanf("%d%d",&n,&m);int i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
}

bool ok(int x)
{
	int i,j;
	for(i=1;i<=n;++i) nw[i]=1,vis[i]=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j) cnt[j]=0;
		for(j=1;j<=n;++j) ++cnt[a[j][nw[j]]];
		int fl=0;
		for(j=1;j<=m;++j) if(cnt[j]>x) vis[j]=fl=1;
		if(!fl) return true;
		for(j=1;j<=n;++j)
		{
			while(vis[a[j][nw[j]]]&&nw[j]<=m)
				++nw[j];
			if(nw[j]>m) return false;
		}
		
	}
	return false;
}

void work()
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(ok(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main()
{
	init();work();
	return 0;
}