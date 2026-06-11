/*  I love Cara Delevingne */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 1e6 + 5;

int tt;
int n, k;
vector<int> g[2005];
int d[2005][2005];
bitset<2005> s[2005];

void build(int v, int p, int st) {
	for (int i = 0; i < sz(g[v]); i++) {
		int to = g[v][i];
		if (p != to) {
			d[st][to] = d[st][v] + 1;
			build(to, v, st);
		}
	}	
}


void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	for (int i = 1; i <= n; i++) {
		build(i, 0, i);
	}
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; ++j) {
	    	if (d[i][j] > k) {
	    		s[i][j] = 1;
	    	}
	    }
	}
	int res = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == k) {
				bitset<2005> cur = s[i] | s[j];
				res = min(res, (int)cur.count());
			}
		}
	}
	(res != inf) ? cout << res : cout << 0;
}


int main() {
  
    tt = 1;
	while (tt--) {
		solve();	
	}
	return 0;
}
