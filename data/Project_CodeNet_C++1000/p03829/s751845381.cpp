#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int M = 1e9+7;

using namespace std;

main()
{
    fast;
    int n,i;
    ll a,b;
    cin>>n>>a>>b;
    ll x[n],ans=0;
    for (i=0;i<n;i++)
        cin>>x[i];
    for (i=0;i<n-1;i++)
        ans+=min((x[i+1]-x[i])*a,b);
    cout<<ans<<endl;
}
