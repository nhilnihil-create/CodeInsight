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

	vector<ll> p;
	vector<ll> see(N + 1, 0);

	ll v = 1;
	p.push_back(v);
	see[1] = 1;


	while (1 == 1) {
		ll bo = 0;

		for(ll w:g[v]) {
			if (see[w] == 0) {
				p.push_back(w);
				see[w] = 1;
				v = w;
				bo = 1;
				break;
			}
		}

		if (bo == 0) { break; }
	}

	vector<ll> q;
	v = 1;
	q.push_back(v);

	while (1 == 1) {
		ll bo = 0;

		for (ll w : g[v]) {
			if (see[w] == 0) {
				q.push_back(w);
				see[w] = 1;
				v = w;
				bo = 1;
				break;
			}
		}

		if (bo == 0) { break; }
	}

	cout << p.size() + q.size() - 1 << endl;
	for (ll i = q.size() - 1; i > 0; i--) { cout << q[i] << " "; }
	rep(i, p.size()) { cout << p[i] << " "; }


	system("PAUSE");
}
