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
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vtype(type) vector<type>
#define vvtype(type) vector<vector<type>>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


ll const MOD = 1e9 + 7;
ll mod_p(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
	x %= MOD;
	if (t == 0) {
		return 1;
	}
	else {
		ll v = mod_pow(x, t / 2);
		if (t % 2 == 0) {
			return v * v % MOD;
		}
		else {
			return v * v%MOD * x %MOD;
		}
	}
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

struct edge
{
	long long to; ll name;
	bool operator<(const edge& rhs) const {
		return name > rhs.name;
	}
};

ll const MAX = 1e5 + 5;
vvtype(edge) G(MAX);
vll color(MAX);
vll parent(MAX);
vvll children(MAX);
vll times(MAX, 0);

void dfs(ll cur, ll& ans, ll k) {
	ll tmp = 0;
	for (auto next : children[cur]) {
		dfs(next, ans, k);
		tmp = max(tmp, times[next]);
	}
	tmp++;
	if (tmp == k && parent[cur] != 1) {
		tmp = 0;
		ans++;
	}
	times[cur] = tmp;
}

int main() {
	ll n, k;
	cin >> n >> k;
	ll ttt;
	cin >> ttt;
	ll ans = 0;
	parent[1] = 1;
	if (ttt != 1) {
		ans++;
	}
	REP(i, 2, n) {
		ll x;
		cin >> x;
		children[x].push_back(i);
		parent[i] = x;
	}
	dfs(1, ans, k);
	cout << ans << endl;
}