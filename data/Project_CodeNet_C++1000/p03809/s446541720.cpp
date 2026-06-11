#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
typedef pair<int,int> pii;
#define mp make_pair
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=200010;
int n,A[N],d[N];
ll f[N];
vector<int>G[N];
void ERROR(){puts("NO");exit(0);}
void dfs(int u,int ff)
{
	ll s=0,mx=0;
	for(int v:G[u])
	{
		if(v==ff)continue;
		dfs(v,u);s+=f[v];mx=max(mx,f[v]);
	}
	if(d[u]==1){f[u]=A[u];return;}
	f[u]=2ll*A[u]-s;
	if(f[u]<0||f[u]>A[u])ERROR();
	if(mx>A[u])ERROR();
}
int main()
{
	n=gi();
	for(int i=1;i<=n;i++)A[i]=gi();
	if(n==2)return puts(A[1]==A[2]?"YES":"NO"),0;
	for(int i=1;i<n;i++)
	{
		int u=gi(),v=gi();d[u]++;d[v]++;
		G[u].push_back(v);G[v].push_back(u);
	}
	int rt=1;
	for(int i=1;i<=n;i++)
		if(d[i]!=1){dfs(rt=i,i);break;}
	puts(f[rt]?"NO":"YES");
	return 0;
}
