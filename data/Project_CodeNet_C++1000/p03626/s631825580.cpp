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

using namespace std;
#define ALL(x)			(x).begin(),(x).end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF				(int)2e9
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))	
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)	
#define FloorN(x, n)	((x)-(x)%(n))			
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define M_PI			3.14159265358979323846
typedef long long			ll;
typedef unsigned long long	ull;
typedef pair<ll, ll>		P;
typedef vector<ll>			VLL;
typedef vector<VLL>			VVLL;
typedef vector<VVLL>		VVVLL;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	int N;
	string S1, S2;
	cin >> N >> S1 >> S2;
	
	int i = 0;
	bool isYoko;
	ll ans = 1;

	if (i + 1 != N && S1[0] == S1[1]) {
		i += 2;
		isYoko = true;
		ans = 6;
	} else {
		i++;
		isYoko = false;
		ans = 3;
	}

	while (i < N) {
		if (i + 1 != N && S1[i] == S1[i + 1]) {
			i += 2;
			ans *= isYoko ? 3 : 2;
			isYoko = true;
		} else {
			i++;
			ans *= isYoko ? 1 : 2;
			isYoko = false;
		}
		ans %= MOD;
	}
	
	cout << ans << endl;
	return 0;
}
