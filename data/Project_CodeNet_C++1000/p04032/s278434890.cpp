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
// メイン
int main()
{
	string S;
	cin >> S;
	int maxSize = S.size();
	REP(i, maxSize - 1) {
		if (S[i] == S[i + 1]) {
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}

		if (i + 2 < maxSize) {
			if (S[i] == S[i + 2]) {
				cout << i + 1<< " " << i + 3 << endl;
				return 0;
			}
		}
	}

	cout << "-1 -1" << endl;
	return 0;
}
