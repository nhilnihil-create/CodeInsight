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

int main(){
	fast_io();
	ll n,m;
	cin >> n >> m;
	ll xans = 0, yans = 0;
	ll x;
	fu(i,1,n){
		cin >> x;
		xans += (2 * i - n - 1) * x;
		xans %= MOD;
	}
	ll y;
	fu(i,1,m){
		cin >> y;
		yans += (2 * i - m - 1) * y;
		yans %= MOD;
	}
	cout << (xans * yans) % MOD << '\n';
}
