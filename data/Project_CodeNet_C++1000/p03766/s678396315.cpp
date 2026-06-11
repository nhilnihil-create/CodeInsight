#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 2000005;

int n;
lint dp[MAXN], sum[MAXN];

int main(){
	cin >> n;
	for(int i=MAXN-1; i>=n; i--) dp[i] = 1, sum[i] = MAXN - i;
	for(int i=n-1; i>=0; i--){
		if(i <= n - 2){
		dp[i] = dp[i + 1] + 1ll * (n - 1) * (n - 1) % mod;
		dp[i] += sum[i + 3] - sum[i + n + 2] + mod;
		dp[i] %= mod;
		}
		else{
			dp[n - 1] = n;
		}
		sum[i] = (sum[i + 1] + dp[i]) % mod;
	}
	cout << dp[0] << endl;
}

