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
	int N;
	cin >> N;
	vector<P> A(100000 + 5);
	REP(i, A.size()) {
		A[i].first = 0;
		A[i].second = i;
	}
	
	REP(i, N) {
		int a;
		cin >> a;
		A[a].first++;
	}
	
	REP(i, A.size()) {
		if (1 <= A[i].first) A[i].first--;
	}
	
	int ans = 0;
	REP(i, A.size()) {
		ans += A[i].first;
	}

	cout << N - CeilN(ans, 2) << endl;

	return 0;
}

