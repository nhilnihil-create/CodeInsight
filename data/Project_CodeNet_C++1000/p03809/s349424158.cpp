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
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int A[N];
vector<int> G[N];

bool DFS(int v, int p = 0) {
	if (sz(G[v]) == 1) return true;
	int mx = 0, sum = 0;
	bool flag = true;
	for (int u : G[v]) if (u != p) {
		flag &= DFS(u, v);
		sum += A[u];
		mx = max(mx, A[u]);
	}
	A[v] += A[v] - sum, sum += A[v];
	mx = max(mx, A[v]);
	flag &= (mx + mx <= sum) && (p || !A[v]) && A[v] >= 0;
	return flag;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i + 1];
	for (int i = 1; i < n; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	if (n == 2) die((A[1] == A[2] ? "YES" : "NO"));
	int r = 0;
	for (int i = 0; i < n; i++) if (sz(G[i + 1]) > 1) r = i + 1;
	cout << (DFS(r) ? "YES" : "NO") << endl;

	return 0;
}
