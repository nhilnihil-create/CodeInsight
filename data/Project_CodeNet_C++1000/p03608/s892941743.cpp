#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    cin.tie(0);
    
    int n,m,r;
    cin >> n >> m >> r;
    
    vector<ll> list(r);
    REP(i,r){
        cin >> list[i];
        --list[i];
    }
    sort(list.begin(),list.end());
    
    vector<vector<ll>>adj(n,vector<ll>(n,INF));
    
    REP(i,n){
        adj[i][i] = 0;
    }
    
    REP(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    //Warshall-Floyd
    REP(k,n){
        REP(i,n){
            REP(j,n){
                if(adj[i][k] != INF && adj[k][j] != INF){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    ll ans=INF;
    do{
        ll tes = 0;
        FOR(i,1,r){
            tes += adj[list[i-1]][list[i]];
        }
        ans = min(ans,tes);
    }while(next_permutation(list.begin(),list.end()));
    COUT(ans);
    return 0;
} 