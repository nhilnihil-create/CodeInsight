// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000, M = 100000;

int pp[N + 1], qq[M + 1];

int main() {
	string s, t; cin >> s >> t;
	int n = s.length(), m = t.length();
	for (int i = 0; i < n; i++)
		pp[i + 1] = pp[i] + s[i] - 'A' + 1;
	for (int j = 0; j < m; j++)
		qq[j + 1] = qq[j] + t[j] - 'A' + 1;
	int q; cin >> q;
	while (q--) {
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		int x = pp[r1] - pp[l1 - 1];
		int y = qq[r2] - qq[l2 - 1];
		cout << (x % 3 == y % 3 ? "YES" : "NO") << '\n';
	}
	return 0;
}
