#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 31);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const ll MOD = 1000000007;
ll ans = 0, n,a;
ll dp[60][60][2501];
int main() {
	cin >> n >> a;
	vector<int> x(n);
	rep(i, n) {
		cin >> x[i];
		dp[i + 1][1][x[i]] = 1;
	}
	rep(i, n) {
		rep(j, n) {
			rep(k, 2501 - x[i]) {
				dp[i + 1][j][k] += dp[i][j][k];
				dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
			}
		}
	}
	rep(i, n+1) {
		ans += dp[n][i][i * a];
	}cout << ans << endl;
}