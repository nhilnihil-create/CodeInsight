#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    ll N,M,R;cin>>N>>M>>R;
    vl visit(R);
    rep(i,R){
        cin>>visit[i];
        visit[i]--;
    }
    vvl cost(N,vl(N,INF));
    rep(i,M){
        ll A,B,C;cin>>A>>B>>C;
        A--,B--;
        cost[A][B]=cost[B][A]=C;
    }
    rep(k,N)rep(i,N)rep(j,N){
        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    }
    sort(all(visit));
    ll ans=INF;
    do{
        ll now=0;
        rep(i,R-1){
            now+=cost[visit[i]][visit[i+1]];
        }
        ans=min(ans,now);
    }while(next_permutation(all(visit)));
    cout<<ans<<endl;
    return 0;
}