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
    ll a;
    map<ll,int> f;
    vector<ll> choose;
    for (i=0;i<n;i++)
    {
        cin>>a;
        f[a]++;
    }
    for (auto e: f)
    {
        if (e.ss>=2)
            choose.pb(e.ff);
    }
    sort(choose.begin(),choose.end());
    if (choose.size()==0)
        cout<<"0\n";
    else if (f[choose[choose.size()-1]]>=4)
        cout<<choose[choose.size()-1]*choose[choose.size()-1]<<endl;
    else if (choose.size()>=2)
        cout<<choose[choose.size()-1]*choose[choose.size()-2]<<endl;
    else
        cout<<"0\n";
}