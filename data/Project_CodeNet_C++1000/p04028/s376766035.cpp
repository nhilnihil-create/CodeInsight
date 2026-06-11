#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

ll mod=1000000007;
ll modpow(ll a, ll b, ll m){
    ll res=1, p=0, now=a;
    for(int i=0; b>p; ++i){
        if(b&((ll) 1<<i)){
            res=(res*now)%m;
            p |= ((ll) 1<<i);
        }
        now=(now*now)%mod;
    }
    return res;
}
ll modinv(ll a, ll m){
    return modpow(a, m-2, m);
}
ll moddiv(ll a, ll b, ll m){
    return (a*modinv(b, m))%m;
}

int main() {
	int N;
	string S;
	cin >> N >> S;
	int p=S.size();
	vector<vector<ll>> dp(N+1);
	dp[0].assign(1, 1);
	for(int i=1; i<=N; ++i){
	    dp[i].assign(i+1, 0);
	    for(int j=0; j<i; ++j){
	        dp[i][j+1]=(dp[i-1][j]*2)%mod;
	        dp[i][max(j-1, 0)]=(dp[i][max(j-1, 0)]+dp[i-1][j])%mod;
	    }
	}
	cout << moddiv(dp[N][p], modpow(2, p, mod), mod) << endl;
	return 0;
}
