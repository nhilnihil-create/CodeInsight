#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n,x;
	cin >> n >> x;
	vector<long long> a(n + 1);
	vector<long long> b(n + 1);
	for (long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > x) {
			b[i] = x;
		}
		else {
			b[i] = a[i];
		}
	}

	for (long i = 1; i < n; i++) {

		if (b[i] + b[i + 1] > x) {
			b[i + 1] = x - b[i];
		}
	}

	long long counter = 0;
	for (long i = 1; i <= n; i++) {
		counter += a[i] - b[i];
	}
	cout << counter << endl;
}