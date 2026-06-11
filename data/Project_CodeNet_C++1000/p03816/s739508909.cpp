#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,a;
    cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        cin>>a;
        mp[a]++;
    }
    ll cnt=0;
    for(auto x:mp) cnt+=x.second-1;
    if(cnt%2) cout<<n-cnt-1<<endl;
    else cout<<n-cnt<<endl;
    return 0;
}