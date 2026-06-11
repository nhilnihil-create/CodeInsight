#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int K,T; cin>>K>>T;
    vector<int> A(T);
    rep(t,0,T) cin>>A.at(t);

    sort(ToEnd(A));
    int64_t sum=accumulate(ToEnd(A),0),ans=0;
    if(A.back()>sum-A.back()) ans=A.back()-(sum-A.back())-1;

    cout<<ans<<endl;
}