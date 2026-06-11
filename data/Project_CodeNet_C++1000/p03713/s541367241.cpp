#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <functional>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(a)					(a).begin(),(a).end()
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						(1000 * 1000 * 1000 * 2)
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
ll getAreaT(ll incHen, ll keepHen)
{
	ll ans = (ll)INF * 10000;
	ll henShort = keepHen / 2;
	ll henLong = keepHen - henShort;
	for (ll i = 1; i < incHen; i++) {
		ll areaS = (incHen - i) * henShort;
		ll areaL = (incHen - i) * henLong;
		ll areaRemain = i * keepHen;
		ll minArea = min(areaS, min(areaL, areaRemain));
		ll maxArea = max(areaS, max(areaL, areaRemain));
		ll diffArea = maxArea - minArea;
		ans = min(ans, diffArea);
	}
	return ans;
}

ll getAreaDiv(ll incHen, ll keepHen)
{
	ll ans;
	ll amari = incHen % 3;
	if (amari == 0) {
		ans = 0;
	} else {
		ans = keepHen;
	}

	return ans;
 }


int main()
{
	ll H, W;
	cin >> H >> W;

	ll ans1 = getAreaT(H, W);
	ll ans2 = getAreaT(W, H);
	ll ans3 = getAreaDiv(H, W);
	ll ans4 = getAreaDiv(W, H);
	ll ans5 = min(ans1, ans2);
	ll ans6 = min(ans3, ans4);
	cout << min(ans5, ans6) << endl;
	return 0;
}

