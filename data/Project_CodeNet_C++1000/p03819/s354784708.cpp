#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL MOD = 1000000007LL;
int l[300000], r[300000];
vector<int> range[100001];
int bit[100001], n;
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += i&-i;
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
		range[r[i] - l[i] + 1].push_back(i);
	}
	n = M;
	int cnt = N;
	for (int d = 1; d <= M; d++) {
		cnt -= range[d].size();
		for (int idx : range[d]) {
			add(l[idx], 1);
			if (r[idx] + 1 <= n) add(r[idx] + 1, -1);
		}
		int ans = cnt;
		for (int i = d; i <= M; i += d) {
			ans += sum(i);
		}
		cout << ans << endl;
	}
}