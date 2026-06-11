#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,K; cin>>N>>K;
    vector<pair<int,int>> Ope(N);
    rep(n,0,N){
        int a,b; cin>>a>>b;
        Ope.at(n)=make_pair(a,b);
    }

    map<int,int64_t> mp;
    for(auto o:Ope) mp[o.first]+=o.second;

    int64_t idx=0,ans;
    for(auto m:mp){
        idx+=m.second;
        if(idx>=K){
            ans=m.first;
            break;
        }
    }

    cout<<ans<<endl;
}