# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
constexpr long long MMOD = 500000004;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)     (x).begin(),(x).end()
# define UNIQ(c)    (c).erase(unique(ALL((c))), end((c)))
# define mp         make_pair
# define eb         emplace_back
# define FOR(i,a,b) for(int i=(a);i<(b);++i)
# define REP(i,n)   FOR(i,0,n)
# define INIT       std::ios::sync_with_stdio(false);std::cin.tie(0);

int n;
string s;
LL dp[5050][5050];
const int MOD = 1e9 + 7;

int main() {
	cin >> n >> s;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5010; j++) {
			if (j == 0) {
				dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			}
			else {
				dp[i][j] = (2 * dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
	LL ans = dp[n][s.size()];
	for (int i = 0; i < s.size(); i++) {
		ans = (ans* MMOD)%MOD;
	}
	cout << ans << endl;
	//system("pause");
}