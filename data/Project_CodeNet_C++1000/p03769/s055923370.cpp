#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main() {
	cin >> n;
	vector<int> ans;

	ll p = 1, ct = 0;
	while (2*p - 1 <= n) {
		p *= 2;
		ct++;
	}

	for (int i = 0; i < ct; ++i)
		ans.push_back(i);
	for (int i = 0; i < ct; ++i)
		ans.push_back(i);

	n -= (p-1);
	int k = 60;

	for (ll j = (1LL<<60); j >= 1; j /= 2, k--) {
		if ((n|j) == n) {
			ct++;
			ans.push_back(ct);
			ans.insert(ans.begin() + k, ct);
		}
	}

	cout << ans.size() << endl;
	for (int i : ans)
		cout << i + 1 << ' ';
	cout << endl;
}