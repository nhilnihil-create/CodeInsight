#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;

ll N, W, w, v, dp[111][555], www, res;

int main() {
	cin >> N >> W;
	for (int i = 0; i != N; ++i) {
		cin >> w >> v;
		if (!i)www = w;
		for (int j = 100; j != -1; --j) {
			for (int k = 0; k != 401; ++k) {
				dp[j + 1][k + w - www] = max(dp[j + 1][k + w - www], dp[j][k] + v);
			}
		}
	}
	for (int i = 0; i != 101; ++i) {
		for (int j = 0; j != 401; ++j) {
			if (i*www + j <= W)res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;
	return 0;
}
