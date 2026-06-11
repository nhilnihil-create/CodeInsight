#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	ll ans = 1e18;
	bool x = true;
	for (int i = 0; i < 2; i++) {
		ll res = 0;
		ll sig = 0;
		for (int j = 0; j < n; j++) {
			if (x) {
				sig += a.at(j);
				x = false;
				if (sig > 0)continue;
				else {
					res += abs(1 - sig);
					sig = 1;
				}
			}
			else {
				sig += a.at(j); 
				x = true;
				if (sig < 0)continue;
				else {
					res += abs(-1 - sig);
					sig = -1;
				}
			}
		}
		x = false;
		ans = min(ans, res);
	}
	cout << ans << endl;
}