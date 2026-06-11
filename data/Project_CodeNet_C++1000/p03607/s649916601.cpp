#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    unordered_map<ll,ll>m;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        m[x]++;
    }
    ll ans=0;
    for(auto x:m)
    {
        if(x.second%2!=0)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}