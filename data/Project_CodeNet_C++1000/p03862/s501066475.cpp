#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD=1e9+7;

int main(){
    ll n,x; cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    ll ans=0;
    for(ll i=0; i<n-1; i++){
        if(a[i]+a[i+1]>x){
            ans+=a[i]+a[i+1]-x;
            a[i+1]=max(0LL,x-a[i]);
        }
    }
    cout<<ans<<endl;
}