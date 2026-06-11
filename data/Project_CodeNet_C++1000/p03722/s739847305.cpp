// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1, m = -1;
		cin >> n >> m;
		if (n <= 0) break;
		vector<LL> a(m), b(m), c(m), d(n, 1LL << 60);
		d[0] = 0;
		for (LL i = 0; i < m; ++i) {
			cin >> a[i] >> b[i] >> c[i];
			--a[i], --b[i];
			c[i] = -c[i];
		}
		auto update = [&]() {
			for (LL j = 0; j < m; ++j) {
				if (d[b[j]] > d[a[j]] + c[j]) {
					d[b[j]] = d[a[j]] + c[j];
				}
			}
		};
		for (LL i = 0; i < n - 1; ++i) {
			update();
		}
		vector<LL> first = d;
		for (LL i = 0; i < n; ++i) {
			update();
		}
		LL ans = -d[n - 1];
		if (ans > -first[n - 1]) {
			cout << "inf" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
