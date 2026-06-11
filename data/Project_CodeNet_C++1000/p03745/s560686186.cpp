#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = 1;
	int sign = 0;
	rep(i, n - 1) {
		if (sign > 0 && a[i] > a[i + 1]) {
			ans++;
			sign = 0;
		}
		else if (sign < 0 && a[i] < a[i + 1]) {
			ans++;
			sign = 0;
		}
		else if (sign == 0) {
			if (a[i] < a[i + 1]) sign = 1;
			if (a[i] > a[i + 1]) sign = -1;
		}
	}
	cout << ans << endl;
	return 0;
}