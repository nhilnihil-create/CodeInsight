#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	vector<int> v;
	rep (i, n) {
		int s;
		cin >> s;
		if (s % 10 != 0) v.push_back(s);
		ans += s;
	}
	if (ans % 10 == 0) {
		if (v.size() == 0) ans = 0;
		else {
			sort(v.begin(), v.end());
			ans -= v[0];
		}
	}
	cout << (ans % 10 == 0 ? 0 : ans) << endl;
	return 0;
}