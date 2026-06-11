#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    int64_t x; cin>>x;
    vector<int64_t> A(N);
    rep(i,0,N) cin>>A.at(i);

    int64_t ans=0;
    rep(i,1,N){
        int64_t sum=A.at(i-1)+A.at(i);
        if(sum>x){
            ans+=sum-x;
            A.at(i)-=min(A.at(i),sum-x);
        }
    }

    cout<<ans<<endl;
}