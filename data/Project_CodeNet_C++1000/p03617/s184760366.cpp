#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll q,h,s,d;
    cin>>q>>h>>s>>d;
    ll n;
    cin>>n;

    ll ans=0;

    if(n>=2)
    {
        ll p=min(min(q*8,h*4),min(s*2,d));
        ans=(n/2)*p;
    }

    if(n%2==1)
    {
        ll p=min(min(q*4,h*2),s);
        ans+=p;
    }

    cout<<ans<<"\n";

    return 0;
}
