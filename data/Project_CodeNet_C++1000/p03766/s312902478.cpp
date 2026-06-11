#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
const int N=1e6+100,mod=1e9+7;
ll par[N];
ll dp[N];
int32_t main(){
    ll n;
    cin >> n;
    dp[1]=n;
    par[1]=n;
    dp[2]=n*n%mod;
    par[2]=par[1]+dp[2];
    par[2]%=mod;
    for (int i=3;i<=n;i++){
        dp[i]=par[max((ll)0,i-3)]+dp[i-1];
        dp[i]+=n-i+2;
        dp[i]+=(n-1)*(n-1)%mod;
        par[i]+=dp[i]+par[i-1];
        par[i]%=mod;
        dp[i]%=mod;
    }
    cout << dp[n];
}
