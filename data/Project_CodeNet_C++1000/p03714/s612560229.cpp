#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e5+5;
ll a[nax*3];
ll dp[3*nax];
ll dp2[3*nax];

multiset<ll> xd;

int main()
{
    int n; cin>>n;
    for(int i=1;i<=3*n;i++) cin>>a[i];
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        xd.insert(a[i]);
    }
    dp[n]=sum;
    for(int i=n+1;i<=2*n;i++)
    {
        if(a[i]>*xd.begin())
        {
            ll akt=*xd.begin();
            sum+=a[i]-akt;
            xd.erase(xd.find(akt));
            xd.insert(a[i]);
        }
        dp[i]=sum;
    }
    sum=0;
    xd.clear();
    for(int i=2*n+1;i<=3*n;i++)
    {
        sum+=a[i];
        xd.insert(a[i]);
    }
    dp2[2*n+1]=sum;
    multiset<ll>::iterator it;
    for(int i=2*n;i>=n+1;i--)
    {
        it=xd.end();
        it--;
        if(a[i]<*it)
        {
            ll akt=*it;
            sum+=a[i]-akt;
            xd.erase(xd.find(akt));
            xd.insert(a[i]);
        }
        dp2[i]=sum;
    }
    ll res=-1e18;
    for(int i=n;i<=2*n;i++) res=max(res,dp[i]-dp2[i+1]);
    cout<<res;
    return 0;
}
