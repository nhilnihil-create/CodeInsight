#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 100000
using namespace std;
typedef long long LL;
int n,m;
LL k;
LL x[MAXN+5];
int ord[MAXN+5];
int ord2[MAXN+5];
LL ans[MAXN+5],fin[MAXN+5];
bool vis[MAXN+5];
vector<int> ned;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]),ord[i]=i;
		ans[i]=x[i]-x[i-1];
	}
	scanf("%d %lld",&m,&k);
	int p;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&p);
		swap(ord[p],ord[p+1]);
	}
	for(int i=1;i<=n;i++)
	{
		p=i;
		ned.clear();
		while(vis[p]==false)
		{
			vis[p]=true;
			ned.push_back(p);
			p=ord[p];
		}
		for(int j=0;j<(int)ned.size();j++)
			ord2[ned[j]]=ned[(1LL*j+1LL*k)%(LL)ned.size()];
	}
	for(int i=1;i<=n;i++)
		fin[i]=ans[ord2[i]];
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=fin[i];
		printf("%lld.0\n",sum);
	}
	return 0;
}