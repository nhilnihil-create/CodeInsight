#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int> S(N);
    rep(n,0,N) cin>>S.at(n);

    priority_queue<int> notTen;
    for(auto s:S) if(s%10!=0) notTen.push(-s);

    int ans=accumulate(ToEnd(S),0);
    if(ans%10==0){
        if(notTen.size()) ans+=notTen.top();
        else ans=0;
    }

    cout<<ans<<endl;
}