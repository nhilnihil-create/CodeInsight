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

ll dp[60][60][3000];
int x[60];
int main() 
{
	int N, A;
	cin >> N >> A;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {						//i番目まで使った
		for (int j = 0; j <= i; j++) {					//j枚のカードを使う
			for (int k = 0; k <= 50 * (j+1); k++) {			//総和がkになる
				dp[i + 1][j][k] += dp[i][j][k];
				if (k >= x[i]) {
					dp[i + 1][j + 1][k] += dp[i][j][k - x[i]];
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp[N][i][i * A];
	}
	cout << ans << endl;
}
