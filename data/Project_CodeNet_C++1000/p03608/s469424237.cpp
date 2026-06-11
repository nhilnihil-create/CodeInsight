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
int d[200][200];
bool used[8];
int r[8];
int R,res=INF;
void dfs(int c,int las,int di){
    if(c==R+1){
        chmin(res,di);
        return;
    }
    REP(i,R)if(!used[i]){
        used[i]=true;
        if(las==-1)dfs(c+1,i,0);
        else dfs(c+1,i,di+d[r[las]][r[i]]);
        used[i]=false;
    }
}

signed main(){
    int n,m;cin>>n>>m>>R;
    REP(i,R){
      	int x;cin>>x;x--;
      	r[i]=x;
    }
    REP(i,n)REP(j,n)d[i][j]=INF;
    REP(i,n)d[i][i]=0;
    REP(i,m){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        d[a][b]=d[b][a]=c;
    }
    REP(k,n)REP(i,n)REP(j,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	dfs(1,-1,0);
  	cout<<res<<endl;
}