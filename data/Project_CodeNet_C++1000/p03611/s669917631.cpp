#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int t,q; cin>>t ;for(q=1;q<=t;q++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,a,mx=0;
    vector<ll>v(100001);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v[a]++;
    }
    for(i=0;i<100000;i++)
    {
        mx=max(mx,v[i]+v[i+1]+v[i+2]);
    }
    cout<<mx;
}
