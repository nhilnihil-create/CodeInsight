#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int nax=5555;
ll dp[nax][nax];
const int mod=1e9+7;

ll pp(ll a,ll b)
{
    if(b==0) return 1;
    ll res=pp(a,b/2);
    res*=res;
    res%=mod;
    if(b%2==1) res*=a;
    res%=mod;
    return res;
}

ll inv(ll a)
{
    return pp(a,mod-2);
}

ll reku(int akt,int mv)
{
    if(dp[akt][mv]!=0) return dp[akt][mv];
    if(max(akt,mv)>5111) return 0;
    if(akt<0 || mv<0) return 0;
    if(akt>mv) return 0;
    if(akt)
    {
        dp[akt][mv]=reku(akt-1,mv-1)*2+reku(akt+1,mv-1);
        dp[akt][mv]%=mod;
        return dp[akt][mv];
    }
    else
    {
        dp[akt][mv]=reku(akt,mv-1)+reku(akt+1,mv-1);
        dp[akt][mv]%=mod;
        return dp[akt][mv];
    }
}

int main()
{
    dp[0][0]=1;
    int n; cin>>n;
    string s; cin>>s;
    ll res=reku(s.length(),n);
    res*=inv(pp(2,s.length()));
    res%=mod; cout<<res;
    return 0;
}
