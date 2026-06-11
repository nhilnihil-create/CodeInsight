#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N),B(N);
    rep(n,0,N) cin>>A.at(n)>>B.at(n);

    int64_t ans=0;
    _rep(i,N-1,0){
        if((A.at(i)+ans)%B.at(i)) ans+=B.at(i)-(A.at(i)+ans)%B.at(i);
    }

    cout<<ans<<endl;
}