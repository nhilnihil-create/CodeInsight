// IOI 2021
 
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int n, k, ans, A[N];
vector<int> G[N];

int DFS(int v) {
	int mx = 0;
	for (int u : G[v]) {
		int d = DFS(u);
		if (d == k - 1 && v != 1) ans++;
		else mx = max(mx, d + 1);
	}
	return mx;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 2; i <= n; i++) G[A[i]].push_back(i);
	ans += (A[1] != 1);
	DFS(1);
	cout << ans << endl;

	return 0;
}