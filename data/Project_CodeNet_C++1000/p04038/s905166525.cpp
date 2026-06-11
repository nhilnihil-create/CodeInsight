#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pr(x) cerr<<#x<<"="<<(x)<<endl
#define pri(x,lo) {cerr<<#x<<"={";for (ll ol=0;ol<=lo;ol++)cerr<<x[ol]<<",";cerr<<"}"<<endl;}
#define inf 100000000
#define N 3000
#define md 1000000007
ll n,k,dp[N][N],i,j,fac[10010000];
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0) {x=1,y=0;return ;}
	exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-(a/b)*y;
}
ll inv(ll a)
{
	ll x=0,y=0;
	exgcd(a,md,x,y);
	x=((x%md)+md)%md;
	return x;
}
ll C(ll n,ll m)
{
	return fac[n]*inv(fac[m])%md*inv(fac[n-m])%md;
}
int main()
{
	scanf("%lld %lld",&n,&k);
	if (k==1) {printf("1\n");return 0;}
	//pr(inv(1));
	fac[0]=1;for (i=1;i<=10000000;i++) fac[i]=(fac[i-1]*i)%md;
	/*for (i=0;i<=10;i++) 
	{
		for (j=0;j<=i;j++)
		printf("%lld ",C(i,j));
		cout<<endl;
	}*/
	dp[0][0]=1;
	for (i=0;i<=n;i++)	
	{
		for (j=i;j<=n;j++)
		{
			if (j==0) continue;
			if (i!=0) dp[i][j]=dp[i-1][j];
			if (i!=j) dp[i][j]=(dp[i][j]+C(j*(k-1)+i-1,k-2)*dp[i][j-1]%md)%md;
			//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	printf("%lld\n",dp[n][n]*fac[n]%md);
}