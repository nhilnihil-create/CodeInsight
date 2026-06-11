#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ll H, W, ans = 1000000000;
	ll size[3];

	cin >> H >> W;

	if (H % 3 == 0 || W % 3 == 0) ans = 0;
	if (H >= 3) ans = min(ans, W);
	if (W >= 3) ans = min(ans, H);

	repc(i, 1, H - 1) {
		int h = H - i;
		int w = W;

		size[0] = W * i;
		size[1] = h * (W / 2);
		size[2] = h * W - size[1];

		sort(size, size + 3);
		ans = min(ans, size[2] - size[0]);
	}

	repc(i, 1, W - 1) {
		int w = W - i;
		int h = H;

		size[0] = H * i;
		size[1] = w * (H / 2);
		size[2] = w * H - size[1];

		sort(size, size + 3);
		ans = min(ans, size[2] - size[0]);
	}

	cout << ans << endl;

	return 0;
}