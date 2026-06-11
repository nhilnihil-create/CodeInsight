#include "bits/stdc++.h"
using namespace std;

int main() {
	long long H, W;
	cin >> H >> W;
	long long ans = 1e18;
	{
		if (0 == W % 3) {
			ans = min(ans, (long long)0);
		}
		else {
			ans = min(ans, H);
		}
	}
	{
		if (0 == H % 3) {
			ans = min(ans, (long long)0);
		}
		else {
			ans = min(ans, W);
		}
	}
	{
		for (long long i = 0; i <= H; ++i) {
			long long x = i * W;
			long long y = (H - i)*(W / 2);
			long long z = (H - i)*(W - W / 2);
			long long tmp = max(x, max(y, z)) - min(x, min(y, z));
			ans = min(ans, tmp);
		}
	}
	{
		for (long long i = 0; i <= W; ++i) {
			long long x = i * H;
			long long y = (W - i)*(H / 2);
			long long z = (W - i)*(H - H / 2);
			long long tmp = max(x, max(y, z)) - min(x, min(y, z));
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}