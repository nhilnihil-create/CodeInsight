#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<uint64_t> A(3*N);
    rep(n,0,3*N) cin>>A.at(n);

    sort(ToEnd(A));
    int cnt=0;
    uint64_t ans=0;
    for(int i=3*N-2;i>=0;i-=2){
        if(cnt>=N) break;
        ans+=A.at(i);
        cnt++;
    }

    cout<<ans<<endl;
}