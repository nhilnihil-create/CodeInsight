#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Comb(int n,int m){
    if(m==0) return 1;

    int64_t v=1;
    m=min(m,n-m);
    rep(i,n-m+1,n+1) v*=i;
    rep(i,1,m+1) v/=i;
    return v;
}

int main(){
    int N,P; cin>>N>>P;
    vector<int> A(N);
    rep(n,0,N) cin>>A.at(n);

    int even=0,odd=0;
    for(auto a:A){
        if(a%2) odd++;
        else even++;
    }

    uint64_t ans=0;
    if(P){
        for(int i=1;i<=odd;i+=2){
            ans+=(uint64_t)pow(2,even)*Comb(odd,i);
        }
    }else{
        for(int i=0;i<=odd;i+=2){
            ans+=(int64_t)pow(2,even)*Comb(odd,i);
        }
    }

    cout<<ans<<endl;
}