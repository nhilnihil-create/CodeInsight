#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
ll dp[1000001];
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		if(n==1)
		{
			cout<<1;
			return 0;
		}
		if(n==2)
		{
			cout<<4;
			return 0;
		}
		dp[0]=n;
		dp[1]=(n*n)%mod;
//		cout<<'k';
		ll s=(dp[0]+dp[1])%mod;
		FOR(i,2,n)
		{
			dp[i]=(s-dp[i-2]+(n-1)*(n-1)+(n-i+1)+mod)%mod;
			s=(s+dp[i])%mod;
//			cout<<dp[i]<<'\n';
		}
		cout<<dp[n-1];
	}
	return 0;
}
