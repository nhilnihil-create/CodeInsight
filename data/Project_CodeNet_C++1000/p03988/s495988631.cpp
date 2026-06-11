#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#define int long long
using namespace std;
int n, a[101], m;
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		m = max(m, p);
		a[p]++;
	}
	int u = m / 2;
	if (m % 2 == 0) {
		if (a[u] != 1) {
			cout << "Impossible\n";
			return 0;
		}
	}
	else {
		u++;
		if (a[u] != 2) {
			cout << "Impossible\n";
			return 0;
		}
	}
	for (int i = u + 1; i <= m; i++)
		if (a[i] < 2) {
			cout << "Impossible\n";
			return 0;
		}
	for (int i = 1; i < u; i++)
		if (a[i] > 0) {
			cout << "Impossible\n";
			return 0;
		}
	cout << "Possible\n";
}