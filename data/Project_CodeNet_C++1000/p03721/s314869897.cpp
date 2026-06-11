#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
 
int main(){
    ll n,k,a,b;
    set<ll> set;
    map<ll,ll> map;
    cin>>n>>k;
    rep(l,n){
        cin>>a>>b;
        if(set.count(a)){
            map[a]+=b;
        }else{
            set.insert(a);
            map[a]=b;
        }
    }
    ll hikaku=0,ans;
    for(auto value:set){
        hikaku+=map[value];
        if(k<=hikaku){
            ans=value;
            break;
        }
    }
    cout<<ans<<endl;
}