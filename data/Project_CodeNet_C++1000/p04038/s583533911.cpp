#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
	return powmod(a, MOD-2);
}
ll f[4000001], invf[4000001];
void fac(int n){
    f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    invf[n]=inv(f[n]);
    for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
}
ll comb(int x, int y){
    if(x<y) return 0;
    return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
    int n, k; cin>>n>>k;
    if(k==1){
        cout<<1<<endl;
        return 0;
    }
    fac(n*k);
    ll dp[2003][2003]={};
    dp[1][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=i-1; j<=n; j++){
            if(j<n){
                dp[i][j+1]+=dp[i][j]*comb(j*(k-1)+i-1+k-2, k-2);
                dp[i][j+1]%=MOD;
            }
            if(j>=i){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }
        }
    }
    cout<<dp[n][n]*f[n]%MOD<<endl;
    return 0;
}