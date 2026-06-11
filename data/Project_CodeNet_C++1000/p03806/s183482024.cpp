#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>



using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A& a, const B& b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A& a, const B& b) { a = max(a, (A)b); };



int main() {
	ll inf = 1e18;
	ll N, MA, MB; cin >> N >> MA >> MB;
	vector<ll> A(1+N), B(1+N), C(1+N);
	REP(i, 1, 1+N) cin >> A[i] >> B[i] >> C[i];
	vector < vector < vector <ll>>> dp(1 + N);
	REP(i, 0, 1 + N) {
		dp[i].resize(401);
		REP(j, 0, 401)dp[i][j].resize(401, inf);
	}
	dp[0][0][0] = 0;
	REP(i, 1, N + 1)REP(j, 0, 401)REP(k, 0, 401) {
		dp[i][j][k] = dp[i - 1][j][k];
		if (j - A[i] >= 0 && k - B[i] >= 0) mins(dp[i][j][k], dp[i - 1][j - A[i]][k - B[i]] + C[i]);
	}
	ll ans = inf;
	REP(j, 1, 401)REP(k, 1, 401) {
		if (j * MB == k * MA)mins(ans, dp[N][j][k]);
	}
	if (ans == inf) PRI(-1);
	else PRI(ans);
	return 0;
}
