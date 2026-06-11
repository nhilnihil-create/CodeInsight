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
    int a,b,c;
    cin>>a>>b>>c;
    if (a+b==c || b+c==a || a+c==b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}