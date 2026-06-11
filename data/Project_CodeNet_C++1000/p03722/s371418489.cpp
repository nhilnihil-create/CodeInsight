#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
#define MOD 1000000007
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

ll n,m;
vvl G(1005);
vvl rG(1005);

bool visit[1005];
bool rvisit[1005];
bool reachable[1005];

void dfs(ll u){
    visit[u] = true;
    for(auto v : G[u]){
        if(visit[v]) continue;
        dfs(v);
    }
}

void rdfs(ll u){
    visit[u] = true;
    for(auto v : rG[u]){
        if(visit[v]) continue;
        rdfs(v);
    }
}

int main(){
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges;
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(b);
        rG[b].push_back(a);
        edges.emplace_back(a,b,-c);
    }
    rep(i,n) reachable[i] = true;
    rep(i,n-1){
        rep(j,n) visit[j] = false;
        dfs(i);
        if(!visit[n-1]) reachable[i] = false;
    }
    REP(i,1,n+1){
        rep(j,n) visit[j] = true;
        rdfs(i);
        if(!visit[0]) reachable[i] = false;
    }
    bool upd = true;
    vl d(n,LINF);
    d[0] = 0;
    ll cnt = 0;
    while(upd){
        upd = false;
        rep(i,m){
            ll a,b,c;
            tie(a,b,c) = edges[i];
            if(!reachable[a]) continue;
            if(!reachable[b]) continue;
            rep(i,n){
                ll dis = d[a] + c;
                if(dis < d[b]){
                    d[b] = dis;
                    upd = true;
                }
            }
        }
        cnt++;
        if(cnt > n){
            puts("inf");
            return 0;
        }
    }
    cout << -d[n-1] << endl;
}
