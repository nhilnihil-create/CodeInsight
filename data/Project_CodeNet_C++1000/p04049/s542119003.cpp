#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
using namespace std;
#define mp make_pair
#define ll long long
#define re register
typedef pair<int,int> pii;
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=2010;
int n,K,tot,dep[N];
vector<int>G[N];
void dfs(int u,int ff)
{
	dep[u]=dep[ff]+1;
	if(dep[u]>K/2)tot++;
	for(int v:G[u])
	{
		if(v==ff)continue;
		dfs(v,u);
	}
}
int main()
{
	n=gi();K=gi();
	for(int i=1;i<n;i++)
	{
		int u=gi(),v=gi();
		G[u].push_back(v);G[v].push_back(u);
	}
	int ans=n;
	if(K&1)
		for(int u=1;u<=n;u++)
			for(int v:G[u])
			{
				tot=0;
				dep[u]=-1;dfs(v,u);
				dep[v]=-1;dfs(u,v);
				ans=min(ans,tot);
			}
	else
		for(int i=1;i<=n;i++)tot=0,dep[i]=-1,dfs(i,i),ans=min(ans,tot);
	printf("%d\n",ans);
	return 0;
}
