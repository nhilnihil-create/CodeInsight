#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,C,K; cin>>N>>C>>K;
    vector<int64_t> T(N);
    rep(n,0,N) cin>>T.at(n);
    sort(ToEnd(T));

    int idx=0,ans=0;
    while(idx<N){
        auto new_idx=upper_bound(ToEnd(T),T.at(idx)+K);
        idx+=min(C,new_idx-T.begin()-idx);
        ans++;
    }

    cout<<ans<<endl;
}