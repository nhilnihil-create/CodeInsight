#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

int n, ma, mb;
int dp[50][500][500];

void solve()
{
	REP(i, 50) REP(a, 500) REP(b, 500) dp[i][a][b] = INF;
	cin >> n >> ma >> mb;
	dp[0][0][0] = 0;
	REP(i, n) {
		int a, b, c; 
		cin >> a >> b >> c;
		REP(x, 500) REP(y, 500) {
			dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y]);
			dp[i + 1][x + a][y + b] = min(dp[i + 1][x + a][y + b], dp[i][x][y] + c);
		}
	}
	int ans = INF;
	RREP(i, 400) {
		if (ma*i > 400 && mb *i > 400) break;
		RREP(j, n) ans = min(ans, dp[j][ma*i][mb*i]);
	}
	cout << (ans < INF ? ans : -1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
