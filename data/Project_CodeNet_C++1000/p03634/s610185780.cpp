#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

vector<ll> dist;
void dfs(const vector<vector<pair<int,ll>>> &G, int v) {

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (dist[next_v.F]>=0) continue; // next_v が探索済だったらスルー
        dist[next_v.F] = dist[v] + next_v.S;
        dfs(G, next_v.F); // 再帰的に探索
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    int N;
    cin >> N;
    vector<vector<pair<int,ll>>> G(N,vector<pair<int,ll>>(0));
    REP(i,N-1){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].pb(mp(b,c));
        G[b].pb(mp(a,c));
    }
    int Q,K;
    cin >> Q >> K;
    K--;
    dist.assign(N,-1);
    dist[K] = 0;
    dfs(G,K);
    REP(i,Q){
        int s,e;
        cin >> s >> e;
        s--;e--;
        cout << dist[s] + dist[e] << "\n";
    }
}