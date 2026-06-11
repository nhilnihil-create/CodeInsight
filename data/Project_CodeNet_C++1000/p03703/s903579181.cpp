#include <cstdio>
#include <cstring>
#include <algorithm>
#define pli pair<long long,int>
#define s1 first
#define s2 second
using namespace std;
int n,k;long long a[200001];pli q[200001];int c[200001];
int query(int x){++x;int ans=0;for(int i=x;i;i-=i&-i)ans+=c[i];return ans;}void add(int x,int p){++x;for(int i=x;i<=n+1;i+=i&-i)c[i]+=p;}
int main()
{
	scanf("%d%d",&n,&k);for(int i=1;i<=n;++i)scanf("%lld",a+i),a[i]+=a[i-1];for(int i=0;i<=n;++i)q[i]=pli(a[i]-1ll*k*i,i);
	long long ans=0;sort(q,q+1+n);for(int i=0;i<=n;++i)
	{
		int pt=i;while(pt<=n&&q[++pt].s1==q[i].s1);--pt;
		for(int j=i;j<=pt;++j)add(q[j].s2,1);for(int j=i;j<=pt;++j)ans+=query(q[j].s2),--ans;i=pt;
	}
	printf("%lld\n",ans);return 0;
}