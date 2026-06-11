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
	REP(c, 26) {
		int topIdx = 0;
		int endIdx = 0;
		for (topIdx = 0; topIdx < maxSize; topIdx++) {
			char str = c + 'a';
			int strCnt = 0;
			for (; topIdx < maxSize; topIdx++) {
				if (str == S[topIdx]) {
					strCnt++;
					break;
				}
			}

			for (endIdx = topIdx + 1; endIdx < maxSize; endIdx++) {
				if (str == S[endIdx]) {
					strCnt++;
					break;
				}
			}

			if (2 <= strCnt) {
				int strNum = endIdx - topIdx + 1;
				if (strNum <= 3) {
					cout << topIdx + 1 << " " << endIdx + 1 << endl;
					return 0;
				}
			}
		}
	}

	cout << "-1 -1" << endl;
	return 0;
}
