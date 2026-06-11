#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dsu[100005],vis[100005],m,x,y,z,u,v,n,i,sum=0,tmp=0;
vector<ll> s[100005];
void dfs(int p,int f,int c)
{
	ll i,v;
	sum++;
	vis[p]=c;
	for(i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(vis[v]==vis[p])tmp=1;
		if(vis[v])continue;
		dfs(v,p,-c);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)dsu[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i])continue;
		sum=tmp=0;
		dfs(i,0,1);
		if(sum==1)x++;
		else 
		{
			if(tmp==0)y++;
			else z++;
		}
	}
	printf("%lld\n",2LL*n*x-x*x+2LL*y*y+z*z+2LL*z*y);
	return 0;
}