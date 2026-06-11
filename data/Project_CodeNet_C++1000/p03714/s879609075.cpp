/* ABC062	D - 3N Numbers */
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
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
// メイン
int main()
{
	int N;
	cin >> N;
	vector<int> a(3 * N);
	REP(i, 3 * N) cin >> a[i];

	// 前半は大きい優先
	vector<ll> fSum(N + 1, 0);
	priority_queue<int, vector<int>, greater<int>> fQue;
	for (int idx = 0; idx < N; idx++) {
		fQue.push(a[idx]);
		fSum[0] += a[idx];
	}
	for (int i = 0; i < N; i++) {
		int val = a[i + N];
		fQue.push(val);
		fSum[i + 1] += (fSum[i] + val - fQue.top());
		fQue.pop();
	}

	// 後半は小さい優先
	vector<ll> bSum(N + 1, 0);
	priority_queue<int> bQue;
	for (int idx = 2 * N; idx < 3 * N; idx++) {
		bQue.push(a[idx]);
		bSum[N] += a[idx];
	}
	for (int i = N - 1; i >= 0; i--) {
		int val = a[i + N];
		bQue.push(val);
		bSum[i] += (bSum[i + 1] + val - bQue.top());
		bQue.pop();
	}

	ll ans = fSum[0] - bSum[0];
	for (int i = 0; i < fSum.size(); i++) {
		ans = max(ans, fSum[i] - bSum[i]);
	}
	cout << ans << endl;
	return 0;
}

