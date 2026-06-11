#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////



int main() {
	ll N, M;
	cin >> N >> M;

	vector<vector<ll>> g(N + 1);
	repn(i, M) {
		ll a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	ll Q;
	cin >> Q;

	vector<ll> v(Q + 1), d(Q + 1), c(Q + 1,0);
	repn(i, Q) cin >> v[i]>>d[i]>>c[i];

	vector<vector<ll>> paint(N + 1, vector<ll>(12, 0));

	for (ll j = 10; j >= 0; j--) {
		repn(i, Q) {
			if (d[i] == j) { paint[v[i]][j] = max(i, paint[v[i]][j]); }
		}

		repn(v, N) {
			for (ll w : g[v]) {
				paint[v][j] = max(paint[v][j], paint[w][j + 1]);
			}
		}
	}

	vector<ll> ans(N + 1,0);
	repn(v, N) {
		rep(j, 11) {
			ans[v] = max(ans[v], paint[v][j]);
		}
	}

	repn(v, N) {
		cout << c[ans[v]] << endl;
	}

	system("PAUSE");
}
