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
	ll n,a,b;
	cin >> n >> a;
	vector<vector<ll>> dp(n+1,vector<ll>(3001,0));
	vector<ll> x(n+1);
	for(int i = 0; i < n; i++) {
		cin >> b;
		x[i+1] = b - a;
	}
	dp[0][1500] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3000; j++) {
			if (j - x[i] >= 0 && j - x[i] <= 3000){
				dp[i][j] = dp[i-1][j] + dp[i-1][j - x[i]]; 
			}
			else if(j - x[i] < 0 || j - x[i] > 3000){
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][1500] - 1 << endl; 
	return 0;
}