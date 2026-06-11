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
const ll MOD = 1000000007;
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
	ll to;
	ll d;
};


///////////////////////////

void Warshall_Floyd(ll N, vector<vector<ll>> &g) {
	repn(k, N) {
		repn(i, N) {
			repn(j, N) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}



int main() {

	ll N, M;
	cin >> N >> M;

	vector<vector<ll>> g(N + 1, vector<ll>(N + 1, INF));

	vector<ll> s(M + 1), t(M + 1), d(M + 1);

	
	repn(i, M) {
		ll a, b, c;
		cin >> a >> b >> c;
		g[a][b] = c;
		g[b][a] = c;

		s[i] = a; t[i] = b; d[i] = c;
	}

	Warshall_Floyd(N, g);

	ll ans = 0;
	repn(i, M) { if (g[s[i]][t[i]] < d[i]) { ans++; } }

	cout << ans;
	

	system("PAUSE");
}
