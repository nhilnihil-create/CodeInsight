#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

ll INF = 1LL << 60;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	ll ans = INF;
	for (int bit = 0; bit < (1 << N); bit++) {
		b = a;
		ll cost = 0;
		int M = b[0];
		int color = 1;
		for (int i = 0; i < N; i++) {
			if (i == 0) continue;
			if (bit & (1 << i)) {
				color++;
				if (M >= b[i]) {
					cost += (M + 1) - b[i];
					b[i] = M + 1;
				}
			}
			M = max(M, b[i]);
		}
		if (color >= K) ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}