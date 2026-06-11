#include <cstdio>
#include <algorithm>
#define ll long long
#define rep(i,j,k) for (i=j;i<=k;i++)
#define down(i,j,k) for (i=j;i>=k;i--)
using namespace std;
const int N=1e5+5,K=70;
int n,m,i,d[N],p[N],a[N];
int lim,j,trans[N][K];
ll sum,x[N];
int main()
{
//	freopen("rabbit.in","r",stdin);
//	freopen("rabbit.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&x[i]),d[i]=x[i]-x[i-1];
	scanf("%d%lld",&m,&sum);
	rep(i,1,m) scanf("%d",&a[i]);
	rep(i,1,n) trans[i][0]=p[i]=i;
	rep(i,1,m) swap(trans[a[i]][0],trans[a[i]+1][0]);
	for (lim=0;(1ll<<lim)<sum;lim++);
	rep(j,1,lim)
		rep(i,1,n) trans[i][j]=trans[ trans[i][j-1] ] [j-1];
	down(j,lim,0)
	{
		if ((1ll<<j)>sum) continue;
		rep(i,1,n) p[i]=trans[p[i]][j];
		sum-=(1ll<<j);
	}
	rep(i,1,n) x[i]=x[i-1]+d[p[i]];
	rep(i,1,n) printf("%lld\n",x[i]);
	return 0;
}