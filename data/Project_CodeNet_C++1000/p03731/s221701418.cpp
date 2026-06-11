#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n,t;
    cin>>n>>t;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        if((a[i+1]-a[i])<t)ans+=a[i+1]-a[i];
        else ans+=t;
    }
    ans+=t;
    cout<<ans;
}