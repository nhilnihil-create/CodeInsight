#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())
const double pi = 3.14159265358979323846;

bool ok(ll t, vector<ll>&h, ll a, ll b)
{
    ll n = sz(h);
    ll i,j,req=0;
    for(i=0;i<n;i++)
    {
        ll cur = h[i]-b*t;
        if(cur>0) req += (cur+(a-b)-1)/(a-b);
    }
    return (req<=t);
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    ll n,a,b,i,j;
    cin>>n>>a>>b;
    vector<ll> h(n);
    for(i=0;i<n;i++) cin>>h[i];
    
    ll x = 0;
    for(ll z=1e10;z>0;z/=2)
    {
        while(!ok(x+z,h,a,b)) x+=z;
    }
    cout<<x+1;
}
