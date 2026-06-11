#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#include <sstream>
#include <complex>
#define BIT(nr) (1ULL << (nr))
#define int long long
#define ll long long
#define double complex<long double>
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	
#define LL_HALFMAX 9223372036854775807 / 2	
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

using namespace std;

int G[15][15];

signed main() {
	int N, K;
	cin >> N >> K;

	vector<int> a(N, 0);
	rep(i, N) {
		cin >> a[i];
	}

	
	int ans = LL_HALFMAX;
	// 見えるようにするビルを全探索
	rep(S, 1 << N) {
		int look = 0;
		int cost = 0;
		int nowMax = a[0] - 1;
		rep(i, N) {
			if (nowMax < a[i]) {
				look++;
				nowMax = a[i];
			}
			// ビットが立ってたら編集してよい
			else if ((1LL << i) & S) {
				look++;
				int addCost = nowMax - a[i] + 1;
				nowMax = nowMax + 1;
				cost += addCost;
			}
		}
		if (look >= K) {
			chmin(ans, cost);
		}
	}

	cout << ans << "\n";

	return 0;
}