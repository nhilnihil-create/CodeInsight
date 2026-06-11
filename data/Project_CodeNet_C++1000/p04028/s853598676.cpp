#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define MOD 1000000007
using namespace std;

int main()
{
	long long int n,ans;
	string s;
	cin >> n;
	cin >> s;
	long long int dp[5003][5003] = {};
	int i,j;
	dp[0][0] = 1;
	for (i = 0; i < n; i++){
		for (j = 0; j < i+2; j++){
			if (j == 0){
				dp[i + 1][0] = (dp[i][0] + dp[i][1])%MOD;
			}
			else{
				dp[i + 1][j] = (dp[i][j - 1] * 2 + dp[i][j + 1])%MOD;
			}
		}
	}
	ans = dp[n][s.length()];
	for (i = 0; i < (int)s.length(); i++){
		ans = ans * 500000004 % MOD;
	}
	cout << ans << endl;

	return 0;
}