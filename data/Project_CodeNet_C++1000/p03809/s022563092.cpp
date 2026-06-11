#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
vector<int> G[100000];
ll c[100000];
ll A[100000];
bool dfs(int v, int par) {
	bool leaf = 1;
	ll sum = 0;
	ll m = 0;
	for (int to : G[v]) {
		if (to == par) continue;
		if (!dfs(to, v)) return 0;
		sum += c[to];
		m = max(m, c[to]);
		leaf = 0;
	}
	if (leaf) {
		c[v] = A[v];
		return 1;
	}
	if (2 * A[v] < sum || sum < A[v]) return 0;
	ll T = 2 * A[v] - sum;
	if (min(sum - m, sum / 2) >= (sum - T) / 2) {
		c[v] = T;
		return 1;
	}
	return 0;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	if (N == 2) {
		if (A[0] == A[1]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int v = 0;
	for (int i = 0; i < N; i++) {
		if (G[i].size() > 1) {
			v = i;
			break;
		}
	}
	bool ok = dfs(v, -1);
	if (c[v] > 0) ok = 0;
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}