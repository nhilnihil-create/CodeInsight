#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n,ma,mb;
int a[42],b[42],c[42];
int dp[42][405][405];
int main() {
	cin>>n>>ma>>mb;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i]>>b[i]>>c[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n * 10; ++j) {
			for (int k = 0; k <= n * 10; ++k) {
				dp[i][j][k] = 1000000;
			}
		}
	}
	dp[0][0][0] = 0;
	int sa = 0;
	int sb = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= sa; ++j) {
			for (int k = 0; k <= sb; ++k) {
				dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
				dp[i+1][j+a[i+1]][k+b[i+1]] = min(dp[i+1][j+a[i+1]][k+b[i+1]], dp[i][j][k] + c[i+1]);
			}
		}
		sa += a[i+1];
		sb += b[i+1];
	}
	int ans = 1000000;
	for (int i = 1; i <= sa; ++i) {
		for (int j = 1; j <= sb; ++j) {
			if (dp[n][i][j] < 1000000 && i * mb == j * ma) {
				ans = min(ans, dp[n][i][j]);
			}
		}
	}
	if (ans < 1000000) cout<<ans<<endl;
	else cout<<"-1"<<endl;
	return 0;
}