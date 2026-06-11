#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
vector<int> G[100000];
void dfs(int v, int p, int dist, vector<ll> &d) {
	d[v] = dist;
	for (int to : G[v]) {
		if (to == p) continue;
		dfs(to, v, dist + 1, d);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<ll> dist1(N), dist2(N);
	dfs(0, -1, 0, dist1);
	dfs(N - 1, -1, 0, dist2);
	int fen = 0, snu = 0;
	for (int i = 0; i < N; i++) {
		if (dist1[i] <= dist2[i]) {
			fen++;
		}
		else {
			snu++;
		}
	}
	if (fen > snu) {
		cout << "Fennec" << endl;
	}
	else {
		cout << "Snuke" << endl;
	}
}