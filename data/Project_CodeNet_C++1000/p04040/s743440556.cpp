#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int h,w,a,b;
const int mod=1e9+7;
const int nax=3e5+5;
ll s[nax];

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
    if(b%2==1) res*=a;
    res%=mod;
    return res;
}

ll inv(ll a)
{
    return pp(a,mod-2);
}

ll nk(ll n,ll k)
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
    ll res=0;
    pre();
    for(int i=1;i<=h-a;i++)
    {
        ll akt=0;
        akt=nk(b-1+i-1,b-1);
        akt*=nk(h-i+w-1-b,h-i);
        res+=akt;
        res%=mod;
    }
    cout<<res;
    return 0;
}
