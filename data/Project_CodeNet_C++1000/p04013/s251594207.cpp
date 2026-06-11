#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>
#include <stack>


#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

constexpr lli mod197 = 1000000007LL;
constexpr lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

lli dp[60][60][50 * 60] = {};
lli x[50];

int main(void) {

	lli N, A;
	cin >> N >> A;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	dp[0][0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= 50 * 50; k++) {
				dp[i + 1][j][k] += dp[i][j][k];
				dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
			}
		}
	}

	lli ans = 0;
	for (int j = 1; j <= N; j++) {
		ans += dp[N][j][j * A];
	}
	COUT(ans);
	return 0;
}