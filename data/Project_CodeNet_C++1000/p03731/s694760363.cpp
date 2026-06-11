#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i;
    ll t,ti;
    cin>>n>>t;
    vector<pair<ll,ll>> a;
    for (i=0;i<n;i++)
    {
        cin>>ti;
        a.pb(mp(ti,ti+t));
    }
    ll x=0,bd=a[0].ff;
    for (i=0;i<n;i++)
    {
        if (bd<=a[i].ss)
            x+=a[i].ss-bd;
        if (i!=n-1)
            bd=max({bd,a[i].ss,a[i+1].ff});
    }
    cout<<x<<endl;
}