#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    long long x[n] , y[m];
    for (int  i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int  i = 0; i < m; i++)
    {
        cin >> y[i];
    }
    const long long mod = 1e9+7;
    long long ans=0;

    long long s=0,t=0;
    for(int i=0;i<n;i++){
        s += (i*x[i])%mod - ((n-1-i)*x[i])%mod;
        s += mod;
        s%=mod;
    }
    for(int i=0;i<m;i++){
        t += (i*y[i])%mod - ((m-i-1) * y[i])%mod;
        t += mod;
        t %= mod;
    }
    ans = t*s;
    ans%=mod;
    cout<<ans<<endl;
    
    
    
}