#include <iostream>
#include <cmath>

using namespace std;

long long mpow(long long a, long long b);

int main()
{
	int n, p;
	cin >> n >> p;
	int a;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0) {
			t++;
		}
	}

	int s = n - t;
	long long ans = 1;
	for (int i = 0; i < t; i++) {
		ans *= 2;
	}
	if (n == t) {
		if (p == 1) {
			cout << 0 << endl;
		} else {
			cout << ans << endl;
		}
	} else {
		for (int i = 1; i < s; i++) {
			ans *= 2;
		}
		cout << ans << endl;
	}

	return 0;
}