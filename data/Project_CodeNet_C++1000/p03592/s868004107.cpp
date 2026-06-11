#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M,K; cin>>N>>M>>K;

    string ans="No";
    rep(i,0,N+1)rep(j,0,M+1){
        if(M*i+N*j-2*i*j==K) ans="Yes";
    }

    cout<<ans<<endl;
}