#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const long long MAXN=100005;
long long n,m;
vector<int>w[MAXN];
bool vis[MAXN];
long long cl[MAXN];
bool dfs(long long u)
{
	vis[u]=1;
	long long re=1;
	for(long long i=0;i<int(w[u].size());i++)
	{
		long long v=w[u][i];
		if(vis[v])
			re&=(cl[u]!=cl[v]);
		else
		{
			cl[v]=cl[u]^1;
			re&=dfs(v);
		}
	}
	return re;
}
int main()
{
	//freopen("squared.in","r",stdin);
	//freopen("squared.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=m;i++)
	{
		long long u,v;
		scanf("%lld %lld",&u,&v);
		w[u].push_back(v);
		w[v].push_back(u);
	}
	long long I=0,O=0,J=0;
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(int(w[i].size())==0)
				I++;
			else if(dfs(i))
				O++;
			else
				J++;
		}
	}
	printf("%lld\n",I*I+I*(n-I)*2+O*O*2+J*J+O*J*2);
	fclose(stdin);
	fclose(stdout);
}