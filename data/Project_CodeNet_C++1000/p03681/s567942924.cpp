#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Kaijo(int n){
    int64_t v=1;
    _rep(i,n,1) {v*=i; v%=MOD;}
    return v;
}

int main(){
    int N,M; cin>>N>>M;

    if(abs(N-M)>1) {cout<<0<<endl; return 0;}
    
    int64_t ans=1;
    ans*=Kaijo(N)%MOD;
    ans*=Kaijo(M)%MOD;
    ans%=MOD;

    if(N==M) {ans*=2; ans%=MOD;}

    cout<<ans<<endl;
}