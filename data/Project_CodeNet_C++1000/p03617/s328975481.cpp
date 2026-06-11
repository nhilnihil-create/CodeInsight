#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.141592653589793238

int main() {
	int Q, H, S, D, N;
	cin >> Q >> H >> S >> D >> N;
	int64_t ans = 0;
	while (N > 0) {
		if (N == 1) {
			if (S <= 2 * H && S <= 4 * Q) {
				ans += S;
			}
			else if (H <= 2 * Q) {
				ans += (int64_t)2 * H;
			}
			else {
				ans += (int64_t)4 * Q;
			}
			N -= 1;
		}
		else {
			if (D <= 2 * S && D <= 4 * H && D <= 8 * Q) {
				ans += (int64_t)N / 2 * D;
				N %= 2;
			}
			else if (S <= 2 * H && S <= 4 * Q) {
				ans += (int64_t)N * S;
				N = 0;
			}
			else if (H <= 2 * Q) {
				ans += (int64_t)2 * N * H;
				N = 0;
			}
			else {
				ans += (int64_t)4 * N * Q;
				N = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}