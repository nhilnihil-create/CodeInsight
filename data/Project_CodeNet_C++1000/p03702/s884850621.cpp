#include <iostream>
#include <vector>

using namespace std;

int main() {

	long long int n, a, b;
	cin >> n >> a >> b;

	vector<long long int> h(n);

	for (long long int i = 0; i < n; i++) {
		cin >> h[i];
	}

	long long int l, r;
	l = 0LL;
	r = 1000000010LL;

	while (r - l > 1) {
		long long int m = (l + r) / 2;

		vector<long long int> h2 = h;

		long long int acount = 0;

		for (long long int i = 0; i < n; i++) {
			h2[i] -= b * m;
			if (h2[i] > 0) {
				long long int ac = h2[i] / (a - b);
				if (h2[i] % (a - b) != 0) {
					ac++;
				}
				acount += ac;
			}
		}

		if (acount <= m) {
			r = m;
		}
		else {
			l = m;
		}
	}

	cout << r << endl;

	return 0;
}