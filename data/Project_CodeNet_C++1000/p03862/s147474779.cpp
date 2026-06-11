#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,x,ans=0,diff;
    cin>>n>>x;
    vector<ll> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];
    if(v[0]>x)
    {
        ans+=v[0]-x;
        v[0]=x;
    }
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]+v[i+1]>x)
        {
            diff=v[i+1]+v[i]-x;
            v[i+1]-=diff;
            ans+=diff;
        }
    }
    cout<<ans;
}
