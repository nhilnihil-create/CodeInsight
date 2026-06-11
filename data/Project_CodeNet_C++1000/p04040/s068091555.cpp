#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int nax=2e5+5;
ll s[nax];
int h,w,a,b;
const int mod=1e9+7;

void pre()
{
    s[0]=1;
    for(int i=1;i<nax;i++)
    {
        s[i]=s[i-1]*i;
        s[i]%=mod;
    }
}

ll pp(ll a,ll b)
{
    if(b==0) return 1;
    ll res=pp(a,b/2);
    res*=res;
    res%=mod;
    if(b&1) res*=a;
    res%=mod;
    return res;
}

ll inv(ll a)
{
    return pp(a,mod-2);
}

ll nk(int n,int k)
{
    ll res=s[n];
    res*=inv(s[k]);
    res%=mod;
    res*=inv(s[n-k]);
    res%=mod;
    return res;
}

int main()
{
    cin>>h>>w>>a>>b;
    pre();
    ll ans=0;
    for(int i=1;i<=h-a;i++)
    {
        ll akt=nk(b-1+i-1,i-1);
        akt*=nk(h-i+w-b-1,h-i);
        akt%=mod;
        ans+=akt;
        if(ans>=mod) ans-=mod;
    }
    cout<<ans;
    return 0;
}
