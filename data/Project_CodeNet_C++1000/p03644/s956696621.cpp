#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define mod 1000000007


int main()
{
    ll n;cin>>n;
    ll ans=0;
    for(ll i=0;i<=32;i++)
    {
        ll x=pow(2,i);
        if(x<=n)
        ans=x;
    }
    cout<<ans<<"\n";
    
}