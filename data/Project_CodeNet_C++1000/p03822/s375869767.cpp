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

ll N;

vector<vector<ll>> g;

ll dfs(ll v){
	ll M = g[v].size();
	if (M == 0) { return 0; }

	vector<ll> a(M);
	rep(i, M) { a[i] = dfs(g[v][i]); }

	sort(a.begin(), a.end());

	ll ret = a[0];

	for (ll i = 1; i < M; i++) {
		ret = max(ret + 1, a[i]);
	}

	return ret + 1;

}


int main() {
	cin >> N;

	g.resize(N + 1);

	repn(i, N - 1) {
		ll a;
		cin >> a;
		g[a].push_back(i+1);
	}

	cout << dfs(1);
	

	system("PAUSE");
}
