#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int mod = 1e9+7;
long frac(int n){
    if(n==0) return 0;
    long m=1;
    for(int i=1;i<=n;i++){
        m *= i;
        m%=mod;
    }
    return m;
}
int main(){
    int n,m;
    cin >> n >> m;
    if(abs(n-m)>1) cout << 0 << endl;
    else{
        long ans = 0;
        ans = frac(n)*frac(m)%mod;
        if(n==m) ans *= 2;
        cout << ans%mod << endl;
    }
}