#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=100005;
vector<int> vct[N];
int n,m,i,j,a[N],p[N],bl[N],cnt,id[N],s[N];
ll K,x[N],d[N],e[N];
void dfs(int x)
{
	if(bl[x])
		return;
	bl[x]=cnt;
	vct[cnt].push_back(x);
	id[x]=s[cnt]++;
	dfs(p[x]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",x+i);
		d[i]=x[i]-x[i-1];
		a[i]=i;
	}
	scanf("%d%lld",&m,&K);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&j);
		swap(a[j],a[j+1]);
	}
	for(i=1;i<=n;++i)
		p[a[i]]=i;
	cnt=0;
	for(i=1;i<=n;++i)
		if(!bl[i])
		{
			++cnt;
			dfs(i);
		}
	for(i=1;i<=n;++i)
		e[vct[bl[i]][(id[i]+K)%s[bl[i]]]]=d[i];
	for(i=1;i<=n;++i)
	{
		e[i]+=e[i-1];
		printf("%lld.0\n",e[i]);
	}
	return 0;
}