#include <bits/stdc++.h>
using namespace std;

char a[128][128];
int cnt[1024];

vector<int> f(vector<int> v) {
	vector<int> ret;
	for (int u : v) if (u) ret.push_back(u);
	return ret;
}

void calc(int n, int m, vector<int> v) {
//	cerr << n << " " << m << endl;
//	for (int u : v) cerr << u << " "; cerr << endl << endl;
	if (n % 2 == 0 && m % 2 == 0) {
		for (int u : v) if (u % 4 != 0) return;
		cout << "Yes" << endl;
		exit(0);
	}
	if ((n & 1) && (m & 1)) {
		bool flg = 0;
		for (auto &it : v) if (it & 1) {
			it--;
			v = f(v);
			flg = 1;
		}
		if (flg == 0) return;
		for (int u : v) if (u & 1) return;
		for (int times = 0; times < (n + m - 2) / 2; times++) {
			sort(v.begin(), v.end(), [](int u, int v) {
				return u % 4 > v % 4;
			});
			v[0]-=2;
			v = f(v);
		}
		for (int u : v) if (u % 4 != 0) return;
		calc(n - 1, m - 1, v);
		return;
	}
	if (n & 1) {
		for (int times = 0; times < m / 2; times++) {
			sort(v.begin(), v.end(), [](int u, int v) {
				return u % 4 > v % 4;
			});
			v[0]-=2;
			v = f(v);
		}
		for (int u : v) if (u % 4 != 0) return;
		calc(n - 1, m, v);
		return;
	}
	if (m & 1) {
		for (int times = 0; times < n / 2; times++) {
			sort(v.begin(), v.end(), [](int u, int v) {
				return u % 4 > v % 4;
			});
			v[0]-=2;
			v = f(v);
		}
		for (int u : v) if (u % 4 != 0) return;
		calc(n, m - 1, v);
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i]; 
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt[a[i][j]]++;
	vector<int> v;
	for (int i = 0; i < 256; i++) if (cnt[i]) v.emplace_back(cnt[i]);
	calc(n, m, v);
	cout << "No" << endl;
	return 0;
}

