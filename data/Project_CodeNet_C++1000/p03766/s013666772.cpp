#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define MOD 1000000007
#define MAXN 205
#define MAXH 20
#define MAXM 52
#define INF 1LL << 30
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
const int N = 1000005;
ll dp[N][2];

ll sqr(ll x, ll mod){
	return (x*x) % mod;
}

ll mod_pow(ll x,ll p,ll mod){
	if(p == 0)return 1;
	return ((p&1?x:1LL) * sqr(mod_pow(x,p/2,mod), mod)) % mod;
}

ll inv(ll x){
	return mod_pow(x, MOD - 2, MOD);
}

ll mul(ll x,ll y){
	return x * y % MOD;
}

ll add(ll x, ll y){
	ll sum = x + y;
	if(sum >= MOD)sum-=MOD;
	return sum;
}

int main(){
	fast_io();
	int n;
	cin >> n;
	dp[1][1] = 1;
	dp[1][0] = n - 1;
	ll rsum = n - 1;
	ll inverse = inv(n - 1);
	fu(i,2,n){
		dp[i][0] = mul((n - 1), dp[i - 1][1]);
		dp[i][1] = add(mul(rsum - dp[i-1][0] + MOD, inverse), dp[i-1][1]);
		rsum = add(dp[i][0], rsum);
	}
	ll ans = add(dp[n][1], dp[n][0]);
	fu(i,1,n - 1)ans = add(ans, mul(n - 1, dp[i][0]));
	fu(i,1,n - 1)ans = add(ans, mul(mul(inverse, i), dp[i][0]));
	cout << ans << '\n';
}
