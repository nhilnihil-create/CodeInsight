#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	M = s.size();
	vector<vector<long long int>>dp(N + 1, vector<long long int>(N + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j != N)dp[i][j] += dp[i - 1][j + 1] * 2;
			if (j)dp[i][j] += dp[i - 1][j - 1];
			else dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[N][M] << endl;
}
