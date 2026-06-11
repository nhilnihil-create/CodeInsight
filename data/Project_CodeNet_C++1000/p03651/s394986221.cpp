#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b);

int main()
{
	int n, k;
	cin >> n >> k;
	int mx = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	if (mx < k) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		int g = a[0];
		for (int i = 1; i < n; i++) {
			g = gcd(g, a[i]);
		}

		if (k % g == 0) {
			cout << "POSSIBLE" << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}

long long gcd(long long a, long long b)
{
	if (a < b) {
		long long t = a;
		a = b;
		b = t;
	}

	long long r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}