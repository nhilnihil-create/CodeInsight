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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

signed main(){
    int n;cin>>n;
    vector<int>ans(n,0);
    vector<pair<int,int>>a(n+1);
    REP(i,n){
        int z;cin>>z;
        a[i]={z,-i};
    }
    a[n]={0,-INF};
    sort(a.rbegin(),a.rend());
    int MI=INF;
    REP(i,n){
        chmin(MI,-a[i].second);
        ans[MI]+=(a[i].first-a[i+1].first)*(i+1);
        a[i].first-=a[i+1].first;
    }
    REP(i,n)cout<<ans[i]<<endl;
}