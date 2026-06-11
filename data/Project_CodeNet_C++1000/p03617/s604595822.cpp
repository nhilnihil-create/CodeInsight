#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t Q,H,S,D,N; cin>>Q>>H>>S>>D>>N;
    
    int64_t sP=min(4*Q,min(2*H,S)),ans=0;
    ans+=min(2*sP,D)*(N/2);
    if(N%2) ans+=sP;

    cout<<ans<<endl;
}