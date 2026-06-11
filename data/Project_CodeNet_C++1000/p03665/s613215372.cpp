#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[60];

ll nPr(ll in, ll ir)
{
    if(in<ir)return 0;
    ll ret=1;
    for(ll i=in;i>=ir+1;i--)ret*=i;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,p;cin>>n>>p;
    bool odd=false;
    for(int i=0;i<n;i++)
    {
        int ia;cin>>ia;

        if(ia%2)odd=true;
    }

    ll ans=1;
    
    if(odd)
    {
        for(int i=0;i<n-1;i++)ans*=2;
    }
    else
    {
        if(p) ans=0;
        else for(int i=0;i<n;i++)ans*=2;
    }
    
    cout<<ans<<"\n";

    return 0;
}
