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
    ll x,y;
    cin>>x;
    y=x%11;
    ll ans=x/11*2;
    if (y==0)
        cout<<ans<<endl;
    else if (y<=6)
        cout<<ans+1<<endl;
    else
        cout<<ans+2<<endl;
}
