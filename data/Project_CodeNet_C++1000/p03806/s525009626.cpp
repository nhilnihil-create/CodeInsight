#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX / 5
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

signed main() {
	int N, Ma, Mb;
	cin >> N >> Ma >> Mb;
	vector<int>a(N);
	vector<int>b(N);
	vector<int>c(N);
	rep(i, N) {
		cin >> a[i] >> b[i] >> c[i];
	}
	int Sa = 0;
	int Sb = 0;
	rep(i, N) {
		Sa += a[i];
		Sb += b[i];
	}
	Sa++;
	Sb++;
	vector<vector<vector<int>>>dp(N + 1, vector<vector<int>>(Sa, vector<int>(Sb,INF)));
	rep(i, N + 1) {
		rep(j, Sa) {
			rep(k, Sb) {
				if (i == 0) {
					if (j == 0 && k == 0) {
						dp[i][j][k] = 0;
					}
				}
				else {
					if (j - a[i - 1] < 0 || k - b[i - 1] < 0) {
						dp[i][j][k] = dp[i - 1][j][k];
					}
					else {
						if (dp[i - 1][j][k] == INF && dp[i - 1][j - a[i - 1]][k - b[i - 1]] == INF) {
							dp[i][j][k] = INF;
						}
						else {
							dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
						}
					}
				}
			}
		}
	}
	int ans = INF;
	rep(i, N + 1) {
		rep(j, Sa) {
			rep(k, Sb) {
				if (i == N && j * Mb == k * Ma &&j!=0&&k!=0) {
					ans = min(ans, dp[i][j][k]);
				}
			}
		}
	}
	if (ans == INF) {
		cout << -1 << enld;
	}
	else {
		cout << ans << endl;
	}
}