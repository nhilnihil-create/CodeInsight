#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int res[1234567], aa[12345678];
signed main() {
	int n, m, x4 = 0, x2 = 0, x1 = 0, ans = 0; cin >> n >> m;
	char a; vector<int>ok(26);
	for (int h = 0; h < n; h++) {
		for (int i = 0; i < m; i++) {
			cin >> a; ok[(int)a - 97]++;
		}
	}
	sort(ok.begin(), ok.end()); reverse(ok.begin(), ok.end());
	x4 = (n / 2) * (m / 2);
	if (n % 2 == 1) { x2 += m / 2; }
	if (m % 2 == 1) { x2 += n / 2; }
	if (n % 2 == 1 && m % 2 == 1) { x1 = 1; }
	int x = 0;
	for (int h = 0; h < x4; h++) {
		while (ok[x] < 4) { x++; if (x == 26) { cout << "No" << endl; return 0; } }
		ok[x] -= 4;
	}
	x = 0;
	for (int h = 0; h < x2; h++) {
		while (ok[x] < 2) { x++; if (x == 26) { cout << "No" << endl; return 0; } }
		ok[x] -= 2;
	}
	x = 0;
	for (int h = 0; h < x1; h++) {
		while (ok[x] < 1) { x++; if (x == 26) { cout << "No" << endl; return 0; } }
		ok[x] -= 1;
	}
	cout << "Yes" << endl;
	return 0;
}