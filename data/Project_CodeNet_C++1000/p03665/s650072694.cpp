#include <bits/stdc++.h>

using namespace std;

map< long long, int > prime_factor(long long n) {
	map< long long, int > ret;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

int main() {

	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	int oddcount=0, evencount=0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			evencount++;
		}
		else {
			oddcount++;
		}
	}

	if (p == 0) {
		if (oddcount == 0) { cout << (long long)pow(2, n) << endl; }
		else {
			cout << (long long)pow(2, evencount)*(long long)pow(2, oddcount) / 2 << endl;;
		}
	}
	else {
		if (oddcount == 0 ) { cout << 0 << endl; }
		else {
			cout << (long long)pow(2, evencount)*(long long)pow(2, oddcount) / 2 << endl;;
		}
	}
	return 0;

}