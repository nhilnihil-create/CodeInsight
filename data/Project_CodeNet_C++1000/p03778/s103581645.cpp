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
    ll w,a,b;
    cin>>w>>a>>b;
    ll x1=a,x2=a+w,y1=b,y2=b+w;
    if (y2<=x1)
        cout<<x1-y2<<endl;
    else if (x2<=y1)
        cout<<y1-x2<<endl;
    else
        cout<<"0\n";
}