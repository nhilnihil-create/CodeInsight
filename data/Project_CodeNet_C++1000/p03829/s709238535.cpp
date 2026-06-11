#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>v;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=1;i<n;i++)
    {
         sum+=min((v[i]-v[i-1])*a,b);
    }
    cout<<sum<<endl;
    return 0;
}