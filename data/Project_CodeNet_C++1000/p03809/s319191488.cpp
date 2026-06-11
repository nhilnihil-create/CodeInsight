#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const long long MAXN=100005;
long long n;
long long d[MAXN],rd[MAXN],yd[MAXN];
vector<int>w[MAXN];
long long key=0;
void dfs(long long u,long long f)
{
	if(key)
		return ;
	long long cnt=0,MX=0,e=0;
	for(long long i=0;i<int(w[u].size());i++)
	{
		long long v=w[u][i];
		if(v!=f)
		{
			e=1;
			dfs(v,u);
			cnt+=d[v];
			MX=max(MX,d[v]);
		}
	}
	if(!e)
		return ;
	if(key)
		return ;
	if(d[u]>cnt)
	{
		key=1;
		return ;
	}
	long long o=cnt-d[u];
	long long yb=min(cnt/2,cnt-MX);
	if(yb<o)
	{
		key=1;
		return ;
	}
	d[u]=cnt-2*o;
	if(d[u]<0)
	{
		key=1;
		return ;
	}
}
int main()
{
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&yd[i]);
	for(long long i=1;i<n;i++)
	{
		long long u,v;
		scanf("%lld %lld",&u,&v);
		w[u].push_back(v);
		w[v].push_back(u);
		rd[u]++;
		rd[v]++;
	}
	//for(long long i=1;i<=n;i++)
	//	d[i]=yd[i];
	//dfs(1,0);
	for(long long i=1;i<=n;i++)
		d[i]=yd[i];
	dfs(n,0);
	if(key)
		printf("NO\n");
	else
		printf("YES\n");
	fclose(stdin);
	fclose(stdout);
}