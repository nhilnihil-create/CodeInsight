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
    ll x,a,b;
    cin>>x>>a>>b;
    if (b-a<=0)
        cout<<"delicious\n";
    else if (b-a<=x)
        cout<<"safe\n";
    else
        cout<<"dangerous\n";
}