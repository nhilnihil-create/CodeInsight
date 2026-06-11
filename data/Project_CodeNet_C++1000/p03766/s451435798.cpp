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
//#include<unordered_map>
//#include<unordered_set>
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
typedef pair<Int, Int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 1000006;
//////////////////////////////

Int dp[N];
Int s[N];

void solve()
{
	Int n;
	cin >> n;
	dp[0] = 1; s[0] = 1;
	dp[1] = n; s[1] = n + 1;

	for (Int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + s[i - 3]) % MOD;
		dp[i] = ((n - 1) * (i - 2) + (n - i + 1) * n + dp[i - 1] + (i >= 3 ? s[i - 3] : 0)) % MOD;
		s[i] = (s[i - 1] + dp[i]) % MOD;
	}
	cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}