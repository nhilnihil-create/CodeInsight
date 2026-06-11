#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	cin >> n;
	long long l = 1, r = 100, lg = 0;
	for (long long i = 0; i <= 50; i++)
		if ((1ll << i) - 1 <= n)
			lg = i;
	n -= (1ll << lg) - 1;
	string s = "";
	for (long long i = 50; i >= 0; i--) {
		if (n >= (1ll << i)) {
			s = '1' + s;
			n -= (1ll << i);
			if (!lg)
				lg = i;
		}
		else
			s = '0' + s;
	}
	vector <int> res;
	for (int i = 1; i <= lg; i++) {
		if (s[i - 1] == '1') {
			res.push_back(r);
			r--;
		}
		res.push_back(i);
	}
	cout << 2 * res.size() << endl;
	for (int i = 1; i <= lg; i++)
		cout << i << " ";
	for (int i = r + 1; i <= 100; i++)
		cout << i << " ";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}
