#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n,W;cin>> n>>W;
	vector<ll> w(n);
	vector<ll> ww(n);
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin>>w[i]>>v[i];
		ww[i] = w[i] - w[0];
	}
	vector<vector<vector<ll>>> dp(n + 1,vector<vector<ll>>(n + 1,vector<ll>(600,0LL)));
	//dp[i][j][k] i番目までを使ってj個使用して重さがkのときの価値の最大値
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			for(ll k = 0; k < 500; k++) {
				if (ww[i - 1] <= k){
					dp[i][j][k] = max(dp[i - 1][j][k],dp[i - 1][j - 1][k - ww[i - 1]] + v[i - 1]);
				}
				else{
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}




	ll ans = 0LL;
	for(ll i = 0; i <= n; i++) {
		ll k = 0;
		while(W - i * w[0] >= k && k < 500){
			ans = max(ans,dp[n][i][k]);
			k++;
		}
	}
	// for(int i = 0; i < 10; i++) {
	// 	cout << dp[n][i].fs << " " << dp[n][i].sc << endl;
	// }
	cout << ans << endl;
	return 0;
}