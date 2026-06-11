#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int A,B,C,D,ans;
    cin>>A>>B>>C>>D;
    ans=min(B,D)-max(A,C);
    if(ans<0)ans=0;
    cout<<ans<<endl;
}