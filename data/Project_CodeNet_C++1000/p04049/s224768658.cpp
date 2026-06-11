#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int n,k;
vector<int> g[2020];
int dep[2020],sz[2020],fr[2020];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	sz[x]=1;
	fr[x]=fa;
	for(int i=0;i<g[x].size();i++)
	{
		int to=g[x][i];
		if(to==fa)continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
int solve(int x)
{
	dep[0]=-1;
	dfs(x,0);
	int cnt=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		if(dep[i]<=k/2)cnt++;
	/*	if(dep[i]==(k+1)/2)
		{
			int has=g[fr[i]].size();
			if(fr[i]!=x)has--;
			mx=max(mx,has);
		}*/
		dep[i]=inf;
	}
	if(k&1)
	{
		dep[x]=0;
		mx=0;
		for(int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			dfs(to,x);
			int tmp=0;
			for(int j=1;j<=n;j++)
			{
				if(dep[j]==(k+1)/2)
				{
				//	cout<<j<<endl;
					tmp++;
				}
				dep[j]=inf;
			}
			mx=max(mx,tmp);
		}
		cnt+=mx;
	}
//	cout<<x<<" "<<cnt<<" "<<mx<<endl; 
	return n-cnt;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("%d\n",n-2);
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,solve(i));
	}
	printf("%d\n",ans);
	return 0;
}