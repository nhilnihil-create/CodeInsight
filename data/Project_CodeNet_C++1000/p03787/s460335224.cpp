#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
bool vis[100000];
int color[100000];
vector<int> G[100000];
int dfs(int v) {
	vis[v] = 1;
	int sum = 1;
	for (int to : G[v]) {
		if (!vis[to]) sum += dfs(to);
	}
	return sum;
}
bool check(int v, int c) {
	color[v] = c;
	for (int to : G[v]) {
		if (color[to] == c) return 0;
		if (!color[to] && !check(to, -c)) return 0;
	}
	return 1;

}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll one = 0;
	ll A = 0, B = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			int s = dfs(i);
			if (s == 1) one++;
			else if (check(i, 1)) A++;
			else B++;
		}
	}
	ll ans = one * one;
	ans += 2 * one*(N - one);
	ans += 2 * A*B;
	ans += 2 * A*A;
	ans += B * B;
	cout << ans << endl;
}
