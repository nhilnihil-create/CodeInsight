
// C - Chocolate Bar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll H, W;
	cin >> H >> W;

	// 横だけで分割
	ll ans1;
	if (H % 3 == 0) ans1 = 0;
	else ans1 = W;

	// 縦だけで分割
	ll ans2;
	if (W % 3 == 0) ans2 = 0;
	else ans2 = H;

	// 横で分割し、残りを縦で分割
	ll ans3 = INF;
	ll W1, W2;
	if (W % 2 == 0) {
		W1 = W / 2;
		W2 = W1;
	} else {
		W1 = W / 2;
		W2 = W1 + 1;
	}

	for (int i=1; i<H; i++) {
		ll T = W * i;
		ll S1 = W1 * (H - i);
		ll S2 = W2 * (H - i);

		if (T < S1) {
			ans3 = min(ans3, S2 - T);
		} else if (T < S2) {
			ans3 = min(ans3, S2 - S1);
		} else {
			ans3 = min(ans3, T - S1);
		}
	}

	// 縦で分割し、残りを横で分割
	ll ans4 = INF;
	ll H1, H2;
	if (H % 2 == 0) {
		H1 = H / 2;
		H2 = H1;
	} else {
		H1 = H / 2;
		H2 = H1 + 1;
	}

	for (int i=1; i<W; i++) {
		ll T = H * i;
		ll S1 = H1 * (W - i);
		ll S2 = H2 * (W - i);

		if (T < S1) {
			ans4 = min(ans4, S2 - T);
		} else if (T < S2) {
			ans4 = min(ans4, S2 - S1);
		} else {
			ans4 = min(ans4, T - S1);
		}
	}

	ll ans = min(ans1, min(ans2, min(ans3, ans4)));

	cout << ans << endl;

	return 0;
}