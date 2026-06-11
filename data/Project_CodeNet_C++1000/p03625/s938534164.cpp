#include <bits/stdc++.h>
using namespace std;

int main() {
	map<long long, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		mp[x]++;
	}
	long long a = 0, b = 0;
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		if (it->second > 1) {
			if (a == 0) {
				a = it->first;
				it->second -= 2;
			}
			if (b == 0 && it->second > 1) {
				b = it->first;
				break;
			}
		}
	}
	cout << a * b;
	return 0;
}