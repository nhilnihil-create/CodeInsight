#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	int n, i, a[100003], t, d[100003] = {};
	ll asum;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	asum = 0;
	t = 0;
	for (i = 0; i < n; i++) {
		asum += a[i];
		if (a[i] == 0) {
			t++;
		}
		else {
			d[t] += (a[i] & 1);
		}
	}

	for (i = 0; i <= t; i++) {
		asum -= (d[i] & 1);
	}

	cout << asum / 2 << endl;

	return 0;
}