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

const int N = 1e5 + 5, D = 1e1 + 1;

bool M[N][D];
int C[N];
vector<int> G[N];

void Q(int v, int d, int c) {
	if (M[v][d]) return;
	M[v][d] = true;
	if (d == 0) {
		C[v] = c;
		return;
	}
	Q(v, d - 1, c);
	for (int u : G[v]) Q(u, d - 1, c);
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	int q; cin >> q;
	vector< pair<int, pii> > qs;
	for (int i = 0; i < q; i++) {
		int v, d, c; cin >> v >> d >> c;
		qs.push_back(make_pair(v, make_pair(d, c)));
	}
	reverse(all(qs));
	for (pair<int, pii> x : qs) Q(x.first, x.second.first, x.second.second);
	for (int i = 1; i <= n; i++) cout << C[i] << endl;

	return 0;
}
