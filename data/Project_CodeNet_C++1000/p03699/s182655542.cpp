#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	int sum = 0;
	vector<int> s(n);
	vector<int> c;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
		if (s[i] % 10 != 0) {
			c.push_back(s[i]);
		}
	}
	if (c.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(c.begin(), c.end());
	if (sum % 10 == 0) {
		sum -= c[0];
	}
	cout << sum << endl;
	return 0;
}