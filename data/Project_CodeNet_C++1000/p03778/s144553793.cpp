#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int W,A,B;cin>>W>>A>>B;
    int x;
    if(A<B)x=B-A-W;
    else x=A-B-W;
    cout<<max(x,0ll)<<endl;
}
