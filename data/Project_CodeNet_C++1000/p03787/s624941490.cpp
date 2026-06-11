#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,n,p,k,A,B,C,vis[N],col[N],Q[N],x,y;
vector<int>v[N]; 
int bfs(int x)
{
	Q[Q[0]=1]=x; vis[x]=1;
	int l=1,i;
	for (;l<=Q[0];++l)
	{
			int p=Q[l];
			for (i=0;i<(int)v[p].size();++i)
			{
					int k=v[p][i];
					if (vis[k]) continue;
					Q[++Q[0]]=k;
					vis[k]=1;
					col[k]=col[p]^1;
			}
	}
	for (i=1;i<=Q[0];++i)
	{
			int p=Q[i];
				for (j=0;j<(int)v[p].size();++j)
					if (col[p]==col[v[p][j]]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;++i)
	{
			scanf("%d%d",&x,&y);
			v[x].pb(y); v[y].pb(x);
	}
	for (i=1;i<=n;++i)	
	if (!vis[i])
	{
		if (bfs(i)) A++; else B++;
		if (Q[0]==1) A--,C++;
	}
	printf("%lld\n",2ll*C*n-1ll*C*C+2ll*A*A+2ll*A*B+1LL*B*B);
}
