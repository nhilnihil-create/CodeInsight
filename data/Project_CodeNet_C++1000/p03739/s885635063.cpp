#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 1e18;
	for (int b = 0; b < 2; b++) {
		long long s = 0, now = 0;
		for (int i = 0; i < n; i++) {
			long long c = i%2==b ? 1 : -1;
			s += a[i];
			if (s <= 0 && c == 1) {
				now += c - s;
				s = 1;
			} else if (s >= 0 && c == -1) {
				now += s - c;
				s = -1;
			}
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}