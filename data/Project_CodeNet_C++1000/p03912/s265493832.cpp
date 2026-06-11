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
    int n,m;cin>>n>>m;
    map<int,int>amari;
    map<int,int>equal;
    REP(i,n){
        int a;cin>>a;
      	int d=a%m;
        amari[d]++;
        if(d!=0&&d*2!=m)equal[a]++;
    }
    int ans=0;
    for(auto v:amari){
        if(v.first==0||v.first*2==m)ans+=v.second/2;
        else{
            int d=min(v.second,amari[m-v.first]);
            ans+=d;
            amari[v.first]-=d;
            amari[m-v.first]-=d;
        }
    }
    for(auto v:equal){
      	int d=v.first%m;
        if(amari[d]<2)continue;
      	if(v.second>=amari[d]){
          	ans+=amari[d]/2;
          	amari[d]=0;
          	continue;
        }
        ans+=v.second/2;
        amari[d]-=(v.second/2)*2;
    }
    cout<<ans<<endl;
}