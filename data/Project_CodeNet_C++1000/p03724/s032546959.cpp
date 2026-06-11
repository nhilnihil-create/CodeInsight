#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n,m;cin>>n>>m;
    map<ll,ll> mp;
    rep(i,0,2*m){
        ll a;
        cin>>a;
        mp[a]++;
    }
    for(auto i:mp){
        if(i.second%2==1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}





