#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
vector<int> L[N], R[N];
int cnt[N], ans[N];
int d[N];
vector<int> dvs[N];
int T[N];

void prepare() {
	d[0] = d[1] = 1;
	for (int i = 2; i <= m; ++i) if (!d[i]) {
		for (int j = i; j <= m; j += i) d[j] = i;
	}

	for (int i = 1; i <= m; ++i) {
		dvs[i].push_back(1);
		int tmp = i;
		while(tmp > 1) {
			int x = d[tmp], c = 0;
			while(tmp % x == 0) tmp /= x, ++c;

			int pw = 1, sz = dvs[i].size();
			for (int j = 1; j <= c; ++j) {
				pw *= x;
				for (int k = 0; k < sz; ++k) {
					dvs[i].push_back(dvs[i][k] * pw);
				}
			}
		}
	}
}

void upd(int x, int v) { for (; x <= m; x += x & -x) T[x] += v; }
int get(int x) { int res = 0; for (; x > 0; x -= x & -x) res += T[x]; return res; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int l, r; cin >> l >> r; ++r;
		L[l].push_back(r - l);
		R[r].push_back(r - l);
		cnt[r - l]++;
	}
	prepare();
	
	for (int i = 1; i <= m; ++i) {
		for (int j : L[i]) upd(j, +1);
		for (int j : R[i]) upd(j, -1);
		for (int j : dvs[i]) {
			ans[j] += get(j - 1);
		}
	}

	for (int i = m; i >= 1; --i) {
		cnt[i] += cnt[i+1];
		ans[i] += cnt[i];
	}

	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}