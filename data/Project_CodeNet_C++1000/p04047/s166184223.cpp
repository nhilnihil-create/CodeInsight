#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>l(n*2);
	for (int i = 0; i < 2*n; i++)cin >> l.at(i);
	sort(l.begin(), l.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += l.at(i * 2);
	}
	cout << ans << endl;
}