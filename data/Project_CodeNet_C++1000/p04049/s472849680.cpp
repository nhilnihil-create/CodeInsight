#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define makeunique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<string> vs;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }

const double pi = acos(-1.);
const int inf = 1e9 + 7;
const int N = 3e5 + 17;

int n, m;
vi g[N];

void dfs(int v, vi& d, vi& fp, int p = -1) {
	for (auto x : g[v])
		if (x != p) {
			d[x] = d[v] + 1;
			fp[x] = fp[v];
			dfs(x, d, fp, v);	 
	    }
}

int solve(int root) {
    vi d(n), fp(n);
	for (auto x: g[root]) {
		d[x] = 1; fp[x] = x;
		dfs(x, d, fp, root);
	}

	vi mi(n, -inf);
	for (int i = 0; i < n; i++)
		if (i != root)
			mi[fp[i]] = max(mi[fp[i]], d[i]);
	int t = inf;

	for (int i = 0; i < n; i++)
		if (mi[i] != -inf)
			t = min(t, mi[i]);		
	int ans = 0;
	if (m & 1) {
		vi tmp(n);
		for (int i = 0; i < n; i++) {
			if (i == root) continue; 
			if (d[i] > m / 2) ans++;
			if (d[i] == m / 2 + 1) tmp[fp[i]]++;
		}
		ans -= *max_element(all(tmp));
	} else {
		for (int i = 0; i < n; i++)
			if (d[i] > m / 2) ans++;
	}
	re ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		g[--x].pb(--y);
		g[y].pb(x);
	}
	int ans = inf;
	for (int i = 0; i < n; i++) {
	    //cout << i + 1 << " " << solve(i) << endl;
		ans = min(ans, solve(i));
	}
	cout << ans;
}
