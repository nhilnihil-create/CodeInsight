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
    int n,c1=0,c2=0,i;
    cin>>n;
    ll a[n];
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]%4==0)
            c1++;
        else if (a[i]%2==0)
            c2++;
    }
    if (c1>=n/2 || 2*c1+c2>=n)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}