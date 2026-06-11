#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int  dp[50][500][500];
int a[50], b[50], c[50];
int main()
{
	int N, M1, M2;
	cin >> N >> M1 >> M2;
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 500; j++) {
			for (int k = 0; k < 500; k++) {
				dp[i][j][k] = mod;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 400; j++) {
			for (int k = 0; k < 400; k++) {
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				dp[i + 1][j + a[i]][k + b[i]] = min(dp[i][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
			}
		}
	}
	int ans = mod;
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			if (i == 0 && j == 0) continue;
			if (i * M2 == j * M1) ans = min(ans, dp[N][i][j]);
		}
	}
	if (ans == mod)cout << -1 << endl;
	else cout << ans << endl;
}