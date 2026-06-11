#include <bits/stdc++.h>

using namespace std;
long long mod,n,dp[2000005],kq,T[2000005],bd,kt,x;
int main()
{
   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    mod=1000000007;
    dp[1]=dp[0]=1;T[0]=1;T[1]=2;
    for (long long i=2;i<=2*n;++i)
    {
        bd=i-n-1;
        kt=min(n-2,i-3);

        dp[i]=dp[i-1];
        T[i]=(T[i-1]+dp[i])%mod;
        if (kt<0) continue;
        x=T[kt];
        if (bd>0) x=(x-T[bd-1]+mod)%mod;
        dp[i]=(dp[i]+x)%mod;
        T[i]=(T[i]+x)%mod;
    }
    kq=(dp[2*n]+dp[n-1]*(n-1)%mod)%mod;
    for (int i=0;i<=n-2;++i) kq=(kq+dp[i]*(n-1)%mod*(n-1)%mod)%mod;
    cout<<kq;
    return 0;
}
