#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N, K;
	cin >> N >> K;

	vector<ll> Ai(N, 0);
	rep(i, N) cin >> Ai[i];

	ll ans = (ll)(1e12);
	for (int i = 0; i < pow(2, N); ++i) {

		ll c_height = Ai[0];
		ll up_cnt = 0;
		int bk_cnt = 1;
		for (int j = 1; j < N; ++j) {
			if ((i >> j & 1) == 1) {
				if (Ai[j] <= c_height) {
					c_height += 1;
					up_cnt = up_cnt + (c_height - Ai[j]);
				}
				else {
					c_height = Ai[j];
				}
				bk_cnt++;
			}
			else
			{
				c_height = max(c_height, Ai[j]);
			}
			

			if (bk_cnt == K) break;
		}

		if (bk_cnt == K) {
			ans = min(ans, up_cnt);
		}
	}

	cout << ans << endl;


	return 0;
}