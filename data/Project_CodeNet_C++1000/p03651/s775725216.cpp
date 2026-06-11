#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	//入力例4:aにk未満しかない→IMPOSSIBLE
	if (k > a.at(n - 1)) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	//aが1つしかない
	if (n == 1) {
		if(a.at(0)==k)cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	// aの最大公約数を求める
	vector<int> b;
	while (true) {
		b.push_back(a.at(0));
		for (int i = 1; i < a.size(); i++) {
			int mod = a.at(i) % b.at(0);
			if (mod == 0)continue;
			else if (mod == b.at(0))continue;
			else b.push_back(mod);
		}
		sort(b.begin(), b.end());
		a = b;
		b.clear();
		if (a.size() == 1)break;
	}
	int64_t gcd = a.at(0);
	//kがその倍数ならPOSSIBLE,無いならIMPOSSIBLE
	if (k % gcd == 0)cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}
