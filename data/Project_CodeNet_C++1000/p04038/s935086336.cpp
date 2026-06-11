#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
const int N=2001*2001+3;
ll mod=1e9+7;
ll dp[2001][2001];
ll fac[N];
ll power(ll n, ll k){
    if (k==0){
        return 1;
    }
    else{
        if (k%2==0){
            ll x=power(n,k/2);
            return x*x%mod;
        }
        else{
            ll x=power(n,k/2);
            x=x*x%mod;
            return x*n%mod;
        }
    }
}
ll fm[N];
ll ent(ll k, ll n){
	if (k==0 || k==n){
        return 1;
	}

	return (((fac[n]*fm[k])%mod)*fm[n-k])%mod;
}
ll pd[N];
int32_t main(){
    sync;
    fac[0] = 1;

	for(int i=1;i<N;i++) {
        fac[i]=(fac[i-1]*i)%mod;
	}
	fm[N - 1] = power(fac[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--) fm[i] = (fm[i + 1] * (i + 1)) % mod;
	ll ans=1;
    ll n,k;
    cin >> n >> k;
    if (k==1){
        cout << 1 << endl;
        return 0;
    }
 //   dp[0]=1;
   // dp[1]=1;
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=i;j>0;j--){
            dp[i][j]=dp[i][j+1];
            dp[i][j]+=dp[i-1][j-1]*ent(k-2,i*k-j-1)%mod*i%mod;
            dp[i][j]%=mod;
        //cout << i << " " << j << " " << dp[i][j] << endl;
        }
        dp[i][0]=dp[i][1];
    }
    cout << dp[n][1] << endl;
    /*
    for (int i=2;i<=n;i++){
        ll p1=1;
        for (int j=1;j<=i;j++){
            dp[i]+=ent(j,i)*ent((k-1)*j-1,i*k-j-1)%mod*pd[j]%mod*dp[i-j]%mod;
           // dp[i]+=(n-i+1)*ent(k-2,i*k-2)%mod*dp[i-1]%mod;
            //dp[i]+=(n-i+1)*ent(k-1,i*k-2)%mod*dp[i-1]%mod*fm[2]%mod;
            cout << i << " " << j << " " << dp[i] << endl;
            dp[i]%=mod;
        }
    }
    cout << dp[n] << endl;
    */
}
