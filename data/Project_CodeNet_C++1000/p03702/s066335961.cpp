#pragma GCC optimize ("O3")
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
#define uint unsigned int
#define MOD 1000000007
#define MAXN 5000
#define MAXH 4
#define MAXM 4
#define INF 1LL << 62
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
const int N = 1005;

int main(){
	int n;
	ll b,a;
	fast_io();
	cin >> n >> a >> b;
	a-=b;
	ll v[n];
	cu(i,0,n)cin >> v[i];
	ll l = 0, r = 1e9+1, m;
	ll ans = MOD;
	while(l <= r){
		m = l + (r-l)/2;
		ll cnt = 0;
		cu(i,0,n){
			cnt += max((v[i] - b * m + a - 1)/a, 0LL);	
		}
		if(cnt > m)l = m + 1;
		else{
			ans = m;
			r = m - 1;
		}
	}
	cout << ans << '\n';
}
