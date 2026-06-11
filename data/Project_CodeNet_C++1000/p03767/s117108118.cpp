#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<long long> a(n*3);
	for (int i = 0; i < n*3; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<long long>());

	long long res = 0;
	for (int i = 1; i < n*2; i = i + 2) {
		res += a[i];
	}

	cout << res << endl;

	return 0;
}