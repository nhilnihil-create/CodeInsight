#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	ll total = 0;
	vector<int>opt;
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		total += a.at(i);
		if (a.at(i) % 10 != 0)opt.push_back(a.at(i));
	}
	sort(a.begin(), a.end());
	sort(opt.begin(), opt.end());
	if (total % 10 != 0) {
		cout << total << endl;
		return 0;
	}
	if (opt.size() != 0) cout << total - opt.at(0) << endl;
	else cout << 0 << endl;
}