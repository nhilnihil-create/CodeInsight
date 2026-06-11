#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
const int MAXM = 1.1e5;
int N, M;

int bit[MAXM];

void update(int i) {
	for (i++; i <= M+1; i += (i & -i)) {
		bit[i]++;
	}
}

int query(int i) {
	int s = 0;
	for (; i; i -= (i & -i)) {
		s += bit[i];
	}
	return s;
}

int query(int l, int r) {
	return query(r) - query(l);
}

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
