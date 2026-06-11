#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll ans, a, x[55], dp[55][55][2600];

ll _max(ll a, ll b){
	if(a > b) return a;
	else return b;
}

int main(){
	cin >> n >> a;
	for(int i = 1; i <= n; ++i) cin >> x[i];
	int X = a;
	for(int i = 0; i <= n; ++i) X = _max(X, x[i]);
	for(int j = 0; j <= n; ++j){
		for(int k = 0; k <= n; ++k){
			for(int s = 0; s <= n*X; ++s){
				if(j == 0 && k == 0 && s == 0) dp[j][k][s] = 1;
				else if(j >= 1 && s < x[j]) dp[j][k][s] = dp[j-1][k][s];
				else if(j >= 1 && k >= 1 && s >= x[j]) dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j]];
				else dp[j][k][s] = 0;
			}
		}
	}
	for(int i = 1; i <= n; ++i) ans += dp[n][i][a*i];
	cout << ans << endl;	
}