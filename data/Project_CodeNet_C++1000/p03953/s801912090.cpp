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
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;

/*
struct point
{
long long name; long long dist;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/

ll const MAX = 100005;
ll x[MAX],a[MAX];
ll d[MAX];
ll p[MAX];
ll u[MAX][100];

void make(ll n, ll m) {
	REP(i, 1, n) {
		u[i][0] = p[i];
	}
	REP(j, 1, 70) {
		REP(i, 1, n) {
			u[i][j] = u[u[i][j - 1]][j - 1];
		}
	}
}

ll q[MAX];

void shif(ll n,ll bin) {
	REP(i, 1, n) {
		q[i] = u[p[i]][bin];
	}
	REP(i, 1, n) {
		p[i] = q[i];
	}
}

ll swp(ll n, ll m, ll k) {
	REP(i, 1, n) {
		p[i] = i;
	}
	REP(i, 1, m) {
		ll c = a[i];
		swap(p[c], p[c - 1]);
	}
	make(n, m);
	REP(i, 1, n) {
		p[i] = i;
	}
	ll bin = 0;
	while (BIT(bin) <= k) {
		bin++;
	}
	while (bin >= 0) {
		if (BIT(bin)&k) {
			shif(n,bin);
		}
		bin--;
	}
	return 0;
}

int main() {
	ll n, m, k;
	cin >> n;
	REP(i, 1, n) {
		cin >> x[i];
		if (i >= 2) {
			d[i - 1] = x[i] - x[i - 1];
		}
	}
	cin >> m >> k;
	REP(i, 1, m) {
		cin >> a[i];
	}
	swp(n-1, m, k);
	cout << x[1] << endl;
	ll cur = x[1];
	REP(i, 1, n-1) {
		cur += d[p[i]];
		cout << cur << endl;
	}
}