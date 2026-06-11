//Wrong Coding:
//j 1 to i not m
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define llong long long
using namespace std;

const int N = 2000;
const int P = 1e9+7;
llong dp[N+3][N+3];
llong fact[5000003],finv[5000003];
int n,m;

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}

llong comb(llong x,llong y) {return x<0 || y<0 || x<y ? 0ll : fact[x]*finv[y]%P*finv[x-y]%P;}

int main()
{
	fact[0] = 1ll; for(int i=1; i<=5000000; i++) fact[i] = fact[i-1]*i%P;
	finv[5000000] = quickpow(fact[5000000],P-2); for(int i=5000000-1; i>=0; i--) finv[i] = finv[i+1]*(i+1)%P;
	scanf("%d%d",&n,&m);
	if(m==1) {printf("1"); return 0;}
	dp[0][0] = 1ll;
	for(int i=1; i<=n; i++)
	{
		dp[i][0] = 1ll;
		for(int j=1; j<=i; j++)
		{
			dp[i][j] = dp[i-1][j];
			dp[i][j] += comb((n-i)+(n-(j-1))*(m-1)-1,m-2)*dp[i][j-1]%P;
			dp[i][j] %= P;
		}
	}
	llong ans = dp[n][n]*fact[n]%P;
	printf("%lld\n",ans);
	return 0;
}