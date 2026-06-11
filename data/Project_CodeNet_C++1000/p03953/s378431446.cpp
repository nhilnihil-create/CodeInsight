#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100010;
int N, M;
ll K;
int X[MAXN];
int dist[MAXN];
ll ans[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	for (int i = 0; i < N - 1; i++) {
		dist[i] = X[i + 1] - X[i];
	}
	vector<int> perm(N - 1);
	iota(perm.begin(), perm.end(), 0);
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		int x; cin >> x; x--;
		swap(perm[x - 1], perm[x]);
	}

	auto go = [&](vector<int> a, vector<int> b) -> vector<int> {
		vector<int> c(N - 1);
		for (int i = 0; i < N - 1; i++) {
			c[i] = a[b[i]];
		}
		return c;
	};

	vector<int> res(N - 1);
	iota(res.begin(), res.end(), 0);
	while (K) {
		if (K & 1) {
			res = go(res, perm);
		}
		perm = go(perm, perm);
		K /= 2;
	}

	ans[0] = X[0];
	for (int i = 0; i < N - 1; i++) {
		ans[i + 1] = ans[i] + dist[res[i]];
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}