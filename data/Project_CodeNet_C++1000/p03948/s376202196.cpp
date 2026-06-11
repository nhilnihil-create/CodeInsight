#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, T;
	cin >> N >> T;
	int mx = (1 << 30), diff = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		mx = min(mx, a);
		if (a - mx > diff) {
			diff = a - mx;
			cnt = 0;
		}
		if (a - mx == diff) {
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}