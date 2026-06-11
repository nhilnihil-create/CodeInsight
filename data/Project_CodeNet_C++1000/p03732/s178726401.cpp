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

signed main(){
    int N,W;cin>>N>>W;
    vector<int> v0,v1,v2,v3;
    int z;
    REP(i,N){
        int w,v;cin>>w>>v;
        if(i==0)z=w;
        w-=z;
        if(w==0)v0.pb(v);
        if(w==1)v1.pb(v);
        if(w==2)v2.pb(v);
        if(w==3)v3.pb(v);
    }
    sort(v0.rbegin(),v0.rend());
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    sort(v3.rbegin(),v3.rend());
    vector<int> v0sum(v0.size()+1,0),v1sum(v1.size()+1,0),v2sum(v2.size()+1,0),v3sum(v3.size()+1,0);
    REPS(i,v0.size()){
        v0sum[i]=v0sum[i-1]+v0[i-1];
    }
    REPS(i,v1.size()){
        v1sum[i]=v1sum[i-1]+v1[i-1];
    }
    REPS(i,v2.size()){
        v2sum[i]=v2sum[i-1]+v2[i-1];
    }
    REPS(i,v3.size()){
        v3sum[i]=v3sum[i-1]+v3[i-1];
    }
    int ans=0;
    REP(i,v0.size()+1){
        REP(j,v1.size()+1){
            REP(k,v2.size()+1){
                REP(l,v3.size()+1){
                    if(z*i+(z+1)*j+(z+2)*k+(z+3)*l>W)continue;
                    chmax(ans,v0sum[i]+v1sum[j]+v2sum[k]+v3sum[l]);
                }
            }
        }
    }
    cout<<ans<<endl;
}