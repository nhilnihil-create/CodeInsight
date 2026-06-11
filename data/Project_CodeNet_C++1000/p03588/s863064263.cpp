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
    ll a,b;
    pair<ll,ll> ans;
    ans.ff=-1;
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        if (ans.ff<a)
        {
            ans.ff=a;
            ans.ss=b;
        }
    }
    cout<<ans.ff+ans.ss<<endl;
}