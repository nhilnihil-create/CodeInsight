#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

template<typename T>
constexpr T divide_ceil(T a, T b)
{
	T remainder = a % b;
	return remainder == 0 ? a / b : (a + (b - remainder)) / b;
}

int main()
{
	ll H, W;
	cin >> H >> W;

	ll S[3];
	ll ans = numeric_limits<int>::max();
	for(int i = 1; i <= H-1; ++i)
	{
		S[0] = W * i;
		ll restH = H - i;
		{
			S[1] = (restH / 2) * W;
			S[2] = divide_ceil(restH, static_cast<ll>(2)) * W;

			ll minS = min({ S[0], S[1], S[2] });
			ll maxS = max({ S[0], S[1], S[2] });

			ans = min(ans, maxS - minS);
		}

		{
			S[1] = restH * (W / 2);
			S[2] = restH * divide_ceil(W, static_cast<ll>(2));

			ll minS = min({ S[0], S[1], S[2] });
			ll maxS = max({ S[0], S[1], S[2] });

			ans = min(ans, maxS - minS);
		}
	}

	for (int i = 1; i <= W-1; ++i)
	{
		S[0] = H * i;
		ll restW = W - i;
		{
			S[1] = (restW / 2) * H;
			S[2] = divide_ceil(restW, static_cast<ll>(2)) * H;

			ll minS = min({ S[0], S[1], S[2] });
			ll maxS = max({ S[0], S[1], S[2] });

			ans = min(ans, maxS - minS);
		}

		{
			S[1] = restW * (H / 2);
			S[2] = restW * divide_ceil(H, static_cast<ll>(2));

			ll minS = min({ S[0], S[1], S[2] });
			ll maxS = max({ S[0], S[1], S[2] });

			ans = min(ans, maxS - minS);
		}
	}

	cout << ans << endl;
}