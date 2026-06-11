#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n; ll k;
    cin>>n>>k;
    map<int,ll>mp;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        mp[a]+=b;
    }
    ll cnt=0;
    for(auto&p:mp){
        cnt+=p.second;
        if(cnt>=k){
            cout<<p.first<<endl;
            return 0;
        }
    }
}
