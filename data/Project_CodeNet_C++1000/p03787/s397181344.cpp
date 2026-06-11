// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int C[N];
vector<int> G[N];
bool ok = true;

int DFS(int v, int c = 1) {
	C[v] = c;
	int sz = 1;
	for (int u : G[v]) {
		if (!C[u]) sz += DFS(u, 3 - c);
		else if (C[u] == C[v]) ok = false;
	}
	return sz;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	int iso = 0, bip = 0, pib = 0;
	for (int i = 1; i <= n; i++) if (!C[i]) {
		ok = true;
		int sz = DFS(i);
		if (sz == 1) iso++;
		else if (ok) bip++;
		else pib++;
	}
	cout << 1LL * iso * iso + 1LL * (n - iso) * iso + 1LL * iso * (n - iso) + 2LL * bip * bip + 1LL * bip * pib + 1LL * pib * bip + 1LL * pib * pib << endl;

	return 0;
}
