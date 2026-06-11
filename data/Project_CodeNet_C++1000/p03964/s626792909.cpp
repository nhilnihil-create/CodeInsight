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
    cin>>n;
    pair<ll,ll> f[n];
    for (i=0;i<n;i++)
        cin>>f[i].ff>>f[i].ss;
    ll x=f[0].ff,y=f[0].ss;
    ll tx,ty;
    for (i=1;i<n;i++)
    {
        tx=x/f[i].ff;
        while (tx*f[i].ff<x)
            tx++;
        ty=y/f[i].ss;
        while (ty*f[i].ss<y)
            ty++;
        x=max(tx,ty)*f[i].ff;
        y=max(tx,ty)*f[i].ss;
    }
    cout<<x+y<<endl;
}