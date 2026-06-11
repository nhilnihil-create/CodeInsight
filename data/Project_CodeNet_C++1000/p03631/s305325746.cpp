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
    int n,r=0,p;
    cin>>n;
    p=n;
    while (p)
    {
        r=r*10+p%10;
        p/=10;
    }
    if (n==r)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}