#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;

struct Dat{
    ll dist;
    ll place;
    ll par;
    bool operator>(const Dat& a) const{
        if(dist!=a.dist) return dist>a.dist;
        return place!=a.place ? place>a.place : par>a.par;
    }
};

typedef priority_queue<Dat,vector<Dat>,greater<Dat> > Dat_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define MUL(a,b) a=(a*b)%mod

vector<P> d[101];
bool used[101][101];
int main(){
    ll N,M; cin>>N>>M;
    rep(i,M){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        d[a].pb(mp(c,b));
        d[b].pb(mp(c,a));
    }
    rep(i,N){
        Dat_queue Q;
        vec memo(N,INF);
        memo[i]=0;
        Dat y={0,i,i};
        Q.push(y);
        while(!Q.empty()){
            Dat x=Q.top();
            Q.pop();
            if(x.dist<=memo[x.place]){
                used[x.par][x.place]=true;
                used[x.place][x.par]=true;
                //cout<<i<<':'<<x.par<<' '<<x.place<<' '<<x.dist<<endl;
                memo[x.place]=x.dist;
                ll A=x.place;
                
                rep(j,d[A].size()) {
                    Dat y={x.dist+d[A][j].first, d[A][j].second,A};
                    Q.push(y);
                }
            }
        }
    }
    ll ans=0;
    rep(i,N) rep(j,d[i].size()){
        ll k=d[i][j].second;
        if(!used[i][k]) ans++;
    }
    cout<<ans/2<<endl;
    
}