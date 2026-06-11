#include <iostream>
using namespace std;
typedef long long ll;
ll N,inf = 1e9+7,dp[5010][5010] = {{0}};
string S;

ll mult(ll n, ll m){
	if(m==1) return n%inf;
	else if(m%2==0){
		ll t = mult(n,m/2);
		return (t*t)%inf;
	}else{
		ll t = mult(n,m-1);
		return (t*n)%inf;
	}
}


int main(){
	cin >> N >> S;
	ll M = S.size();
	dp[0][0] = 1;
	for(int j=1;j<=N;j++){
		for(int i=0;i<=N;i++){
			dp[i][j] += dp[i+1][j-1];
			if(i>=1) dp[i][j] += 2*dp[i-1][j-1];
			else dp[i][j] += dp[i][j-1];
			dp[i][j] %= inf;
		}
	}
	ll ans = 0;
	cout << (dp[M][N]*mult(mult(2,M),inf-2))%inf << endl;
}