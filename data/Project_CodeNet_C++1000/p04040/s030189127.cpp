#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
const int modu = 1e9 + 7;
int H, W, A, B;
ll inv[maxn+5], c1[maxn+5], c2[maxn+5];

int main() {
	inv[1] = 1;
	for (int i = 2; i <= maxn; ++i)
		inv[i] = inv[modu % i] * (modu - modu/i) % modu;
	cin >> H >> W >> A >> B;
	ll ans = 0;
	c1[0] = 1;
	for (int i = 1; i <= H-A+B-1; ++i)
		c1[i] = c1[i-1] * (H-A+B-i) % modu * inv[i] % modu;
	c2[0] = 1;
	for (int i = 1; i <= W-B+A-1; ++i)
		c2[i] = c2[i-1] * (W-B+A-i) % modu * inv[i] % modu;
	for (int i = H-A-1, j = W-B-1; i >= 0 && j >= 0; --i, --j)
		ans = (ans + c1[H-A+B-1-i] * c2[W-B+A-1-j] % modu) % modu;
	cout << ans << endl;
	return 0;
}