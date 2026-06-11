/*
        Author: Prokash
                CSE48, JU
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,in,t;
    cin>>t;
    vector<ll>v;
    ll sum=0;
    for(ll i=0;i<t;i++)
    {
        cin>>in;
        sum+=in;
        v.push_back(in);
    }
    ll s,d=0;
    ll ans=INT_MAX;
    for(ll i=0;i+1<t;i++)
    {
        d+=v[i];
        s=abs(sum-2*d);
        ans=min(ans,s);
    }
    cout<<ans<<endl;
    return 0;
}