#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	vector<long long>sigma = a;
	for (int i = 1; i < n; i++) {
		sigma.at(i) = sigma.at(i - 1) + sigma.at(i);
	}
	reverse(sigma.begin(), sigma.end());
	for (int i = 0; i < n - 1; i++) {
		if (sigma.at(i) > sigma.at(i + 1) * 3) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << n << endl;

	// 100 60 30 10 3 1
}