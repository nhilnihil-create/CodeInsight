#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
int hyd(int x,int y){
    if(x%y==0)return x/y;
    else return x/y+1;
}

signed main(){
    int N;cin>>N;
    int A=1,B=1;
    REP(i,N){
        int x,y;cin>>x>>y;
        int n=max(hyd(A,x),hyd(B,y));
        A=n*x;B=n*y;
    }
    cout<<A+B<<endl;
}
