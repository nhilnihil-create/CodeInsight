#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct point
{
	long long i; long long j;
};

ll const MOD = 1e9 + 7;
ll const MAX = 1e6 + 6;

ll mod_p(ll x, ll y) {
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	return (x*y) % MOD;
}

ll dp[MAX] = {}, dp_sum[MAX] = {};

int main() {
	ll n;
	cin >> n;
	dp[1] = dp_sum[1] = n;
	dp[2] = n * n%MOD;
	dp_sum[2] = mod_p(dp[1], dp[2]);
	REP(i, 3, n) {
		ll j = n;
		ll t = n - i + 2;
		dp[i] = (mod_m(j, t) +mod_m((j - 1),(j - t - 1)) + dp_sum[i - 1] - dp[i - 2] + MOD) % MOD;
		//cout << dp[i] << endl;
		dp_sum[i] = mod_p(dp_sum[i - 1], dp[i]);
	}
	cout << dp[n] << endl;
}