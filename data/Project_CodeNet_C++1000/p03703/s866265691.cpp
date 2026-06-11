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
const int N = 200005;
ll cnt = 0;
long long t[N + 5];

void inc(int x,long long val){
	for(++x;x <= N;x += x&-x){
		t[x] += val;
	}
}

long long query(int x){
	ll res = 0;
	for(++x;x > 0; x&=x-1){
		res += t[x];
	}
	return res;
}

int main(){
	fast_io();
	ll n,k;
	cin >> n >> k;
	ll a[n+1];
	fu(i,1,n)cin >> a[i];
	fu(i,1,n)a[i] += a[i-1];
	vector<pll> v(n+1);
	fu(i,0,n){
		v[i] = {a[i] - k * i, i};
	}
	sort(all(v), greater<pll>());
	ll ans = 0;
	fu(i,0,n){
		++cnt;
		inc(v[i].S, 1);
		ans += cnt - query(v[i].S);
	}
	cout << ans << '\n';
}
