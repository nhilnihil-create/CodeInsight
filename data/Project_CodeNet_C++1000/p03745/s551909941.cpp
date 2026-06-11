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
typedef long long           ll;
#define REP(i, n)           for (ll i = 0 ; i < (ll)n ; ++i)
#define REPN(i, m, n)       for (ll i = m ; i < (ll)n ; ++i)
#define INF                 (ll)1e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef pair<ll, ll>	    P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for_each(ALL(A), [](ll &a){ cin >> a; });

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	auto getSt = [](ll a, ll b)
	{
		if (a == b) {
			return 0;
		} else if (a < b) {
			return 1;
		} else {
			return 2;
		}
	};

	ll status = getSt(A[0], A[1]);
	ll ans = 1;
	REPN(i, 1, N - 1) {
		int nextStatus = getSt(A[i], A[i + 1]);
		if (status == 0) {
			status = nextStatus;
		} else if (status == 1) {
			if (nextStatus == 2) {
				status = 0;
				ans++;
			}
		} else {
			if (nextStatus == 1) {
				status = 0;
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
