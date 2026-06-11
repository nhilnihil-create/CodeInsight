#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> P;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

const ll MAXN=100010;
ll memo[MAXN];
vec d[MAXN], D[MAXN];

bool used[MAXN];


void INIT(ll a){
    used[a]=true;
    rep(i,d[a].size()){
        ll b=d[a].at(i);
        if(!used[b]){
            D[a].pb(b);
            INIT(b);
        }
    }
    return;
}

ll dfs(ll x){
    if(memo[x]>=0) return memo[x];
    if(D[x].size()==0) return memo[x]=0;
    ll ret=0;
    rep(i,D[x].size()){
        ll a=D[x].at(i);
        ret^=(dfs(a)+1);
    }
    return memo[x]=ret;
}
int main(){
    ll N; cin>>N;
    rep(i,N-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        d[a].pb(b);
        d[b].pb(a);
    }
    INIT(0);

    rep(i,MAXN) memo[i]=-INF;
    if(dfs(0)) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    

}