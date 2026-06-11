#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b;cin>>n>>a>>b;

    ll ans=0;

    if(n==1)
    {
        if(a==b)ans=1;
        else ans=0;
    }
    else
    {
        n-=2;
        ll nmax=a+b;
        ll nmin=a+b;
        for(int i=0;i<n;i++)
        {
            nmax+=b;
            nmin+=a;
        }
        ans=max(nmax-nmin+1,0LL);
    }
    
    cout<<ans<<"\n";

    return 0;
}
