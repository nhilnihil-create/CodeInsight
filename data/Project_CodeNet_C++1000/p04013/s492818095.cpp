#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <assert.h>
#include <functional>
#include <unordered_map>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						(int)2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/

int main()
{
	int N, A;
	string S;
	cin >> N >> A;
	vector<ll> x(N);
	REP(i, N) cin >> x[i];
	REP(i, N) x[i] -= A;
	sort(x.begin(), x.end());

	int valMax = N * 50;
	int halfVal = valMax / 2;
	vector<vector<ll>> dp(N + 1, vector<ll>(valMax, 0));
	
	dp[0][halfVal] = 1;
	REP(i, N) {
		REP(j, valMax) {
			if (0 < dp[i][j]) {
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j + x[i]] += dp[i][j];
			}
		}
	}

	cout << dp[N][halfVal] - 1<< endl;
	return 0;
}

