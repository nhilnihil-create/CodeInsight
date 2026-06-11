#include <iostream>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int n, a[100000]; char op[100000];
long long dp[100010][3];

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	op[0] = '+';
	rep(i, n){
		cin >> a[i];
		if(i != n - 1) cin >> op[i + 1];
	}
	rep(i, n + 1) rep(j, 3) dp[i][j] = -1e18;
	dp[0][0] = 0;
	rep(i, n) rep(j, 3) if(dp[i][j] > -1e18){
		if(j < 2 && op[i] == '-'){
			int nj = j + 1;
			dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + (j & 1 ? a[i] : -a[i]));
		}
		for(int nj = j; nj >= 0; nj--){
			dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + (j & 1 ^ op[i] == '+' ? a[i] : -a[i]));
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}