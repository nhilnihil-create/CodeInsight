#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Gcd(int64_t n, int64_t m){
    if(n%m==0) return m;
    return Gcd(m,n%m);
}

int main(){
    int64_t N,K; cin>>N>>K;
    vector<int64_t> A;
    rep(n,0,N) {
        int64_t a; cin>>a;
        A.emplace_back(a);
    }
    
    int64_t gcd=A.front(), maxA=A.front();
    rep(i,1,N){
        maxA=max(maxA,A.at(i));
        gcd=Gcd(gcd,A.at(i));
    }

    string ans="IMPOSSIBLE";
    if(K<=maxA && K%gcd==0) ans="POSSIBLE";
    cout<<ans<<endl;
}