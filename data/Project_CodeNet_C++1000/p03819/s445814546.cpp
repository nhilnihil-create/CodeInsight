#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
const int MAXM = 1.1e5;
const int S = 1 << 17;

int seg[S * 2];

void update(int i) {
	for (int a = i+S; a; a /= 2) {
		seg[a]++;
	}
}

int query(int l, int r) {
	int ans = 0;
	for (int a = l+S, b = r+S; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			ans += seg[a++];
		}
		if (b & 1) {
			ans += seg[--b];
		}
	}
	return ans;
}

int N, M;
vector<int> facs[MAXM];
vector<int> rights[MAXM];
int ans[MAXM];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int l, r; cin >> l >> r;
		rights[l].push_back(r);
	}
	for (int d = 1; d <= M; d++) {
		for (int v = d; v <= M; v += d) {
			facs[v].push_back(d);
		}
	}
	for (int v = 1; v <= M; v++) {
		for (int r : rights[v]) {
			update(r);
		}
		for (int d : facs[v]) {
			ans[d] += query(v, min(M+1, v+d));
		}
	}
	for (int d = 1; d <= M; d++) {
		cout << ans[d] << '\n';
	}

	return 0;
}
