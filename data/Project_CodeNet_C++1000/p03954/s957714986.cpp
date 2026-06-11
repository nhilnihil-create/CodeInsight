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


struct edge
{
	long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

ll const MAX = 2e5 + 5;
ll a[MAX];
ll b[MAX];
bool ok(ll n,ll m ,ll x) {
	REP(i, 1, m) {
		b[i] = (a[i] >= x);
	}
	ll c = b[n];
	REP(i, 1, n - 1) {
		if ((!(b[n - i + 1] ^ b[n - i])) || !((b[n + i - 1] ^ b[n + i]))) {
			return b[n - i + 1];
		}
	}
	if (n % 2 == 0) {
		return !b[n];
	}
	else {
		return b[n];
	}
}

int main() {
	cin.tie(0);
	ll n;
	cin >> n;
	ll m = 2 * n - 1;
	REP(i, 1, m) {
		cin >> a[i];
	}
	ll ub = m; ll lb = 1;
	while (ub - lb > 1) {
		ll mid = (ub + lb) / 2;
		if (ok(n,m,mid)) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	}
	cout << lb << endl;
}