#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a.at(i) >= 2) {
			ans += a.at(i) / 2;
			a.at(i) %= 2;
		}
		if (i!=n-1&&a.at(i) == 1 && a.at(i + 1) >= 1) {
			ans++;
			a.at(i) = 0;
			a.at(i + 1)--;
		}
	}
	cout << ans << endl;
}