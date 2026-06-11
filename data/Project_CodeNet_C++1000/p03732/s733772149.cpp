#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (int)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>        P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	ll N, W;
	cin >> N >> W;
	vector<ll> w(N, 0);
	vector<ll> v(N, 0);
	REP(i, N) cin >> w[i] >> v[i];

	ll w1 = w[0];
	vector<vector<ll>> wType(4);
	REP(i, N) {
		wType[w[i] - w1].emplace_back(v[i]);
	};
	REP(i, 4) {
		sort(wType[i].rbegin(), wType[i].rend());
	}
	
	vector<vector<ll>> wSum(4);
	REP(i, 4) {
		wSum[i].emplace_back(0);
		REP(j, wType[i].size()) {
			wSum[i].emplace_back(wType[i][j] + wSum[i][j]);
		}
	}

	ll ans = 0;
	REP(i0, wSum[0].size()) {
		REP(i1, wSum[1].size()) {
			REP(i2, wSum[2].size()) {
				REP(i3, wSum[3].size()) {
					ll totalWeight = i0 * w1 + i1 * (w1 + 1) + i2 * (w1 + 2) + i3 * (w1 + 3);
					if (totalWeight <= W) {
						ll ansOne = wSum[0][i0] + wSum[1][i1] + wSum[2][i2] + wSum[3][i3];
						ans = max(ans, ansOne);
					}
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
