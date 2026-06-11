//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int n, p;
	cin >> n >> p;
	vector<int> a(n+1);
	REP1(i, n) cin >> a[i];
	ll dp[n+1][2];
	dp[0][0] = 1; dp[0][1] = 0;
	REP1(i, n) {
		if(a[i] % 2 == 0){
			dp[i][0] = dp[i-1][0] * 2;
			dp[i][1] = dp[i-1][1] * 2;
		}
		else{
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][1] + dp[i-1][0];
		}
	}
	cout << dp[n][p] << endl;
}