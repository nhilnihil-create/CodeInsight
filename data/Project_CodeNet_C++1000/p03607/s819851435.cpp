#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll mod=998244353;

int main(){
    ll n;
    cin>>n;
    
    map<ll,ll> m;
    for(ll i=1;i<=n;++i){
        ll t;
        cin>>t;
        m[t]++;
    }
    ll cnt=0;
    for(auto v:m){
        cnt+=v.second%2;
    }
    cout<<cnt;
}