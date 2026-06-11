#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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

signed main(){
    int n,x;cin>>n>>x;
    if(abs(n-x)>n-2){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    if(n-x==0){
        REPS(i,2*n-1)cout<<i<<endl;
    }
    if(n-x<=-1){
        REPS(i,2*n-1-(x-n))cout<<i+x-n<<endl;
        REPS(i,x-n)cout<<i<<endl;
    }
    if(n-x>=1){
        REPS(i,n-x)cout<<2*n-1-(n-x)+i<<endl;
        REPS(i,2*n-1-(n-x))cout<<i<<endl;
    }
}