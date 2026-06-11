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
struct MyCin {
	void operator()(P &a) {
		cin >> a.first >> a.second;		
	}
};

int main()
{
	ll N;
	cin >> N;
	vector<pair<ll, ll>> A(N);
	for_each(ALL(A), MyCin());
	reverse(ALL(A));

	ll addSum = 0;
	for (auto one : A) {
		ll addAll = one.first + addSum;
		ll addOne = CeilN(addAll, one.second) - addAll;
		addSum += addOne;
	}

	cout << addSum << endl;
	return 0;
}
