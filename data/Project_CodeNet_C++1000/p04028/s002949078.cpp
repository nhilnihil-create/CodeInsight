#include <iostream>
#include <algorithm>
#include <array>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

#define INT_MAX 2000000000
#define MOD 1000000007
#define ll long long
#define rep(i,a,b) for(i = (a); i < (b); i++)
#define bitget(a,b) (((a) >> (b)) & 1)

using namespace std;



int main() {
	int i, j, k;
	int n;
	string s;
	cin >> n;
	cin >> s;
	ll int dp[5003][5003] = {};
	dp[0][0] = 1;
	rep(i, 1, n+1) {
		rep(j, 0, i+1) {
			if (j == 0) {
				dp[i][j] = (dp[i - 1][j + 1] * 2 + dp[i - 1][j]) % MOD;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2) % MOD;
			}
		}
	}
	cout << dp[n][s.length()] << endl;
	return 0;
}