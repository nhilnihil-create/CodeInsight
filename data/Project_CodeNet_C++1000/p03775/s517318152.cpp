#include<iostream>
#include<math.h>
using namespace std;

int main() {
	auto F = [](int a, int b) {
		int cnt1 = 0, cnt2 = 0;
		while (a) {
			a /= 10;
			cnt1++;
		}
		while (b) {
			b /= 10;
			cnt2++;
		}
		return (cnt1 > cnt2 ? cnt1 : cnt2);
	};
	long long n, ans; cin >> n;
	ans = F(1, n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (ans > F(i, n / i)) {
				ans = F(i, n / i);
			}
		}
	}
	cout << ans << endl;

	return 0;
}