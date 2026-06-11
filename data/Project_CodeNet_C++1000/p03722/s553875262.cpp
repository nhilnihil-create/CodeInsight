#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e16;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 2510;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
struct Edge{
    ll from,to,cost;
};
class Bellman_Ford{
    private:
        vector<Edge> edges;
        vector<ll> d;
        ll V;
    public:
        Bellman_Ford(vector<Edge>& g,ll v):edges(g),V(v){
            d.resize(v,INF);
        }
        bool bellman_ford(ll s){
            d[s] = 0;
            rep(i,V){
                rep(j,edges.size()){
                    Edge e = edges[j];
                    if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost){
                        d[e.to] = d[e.from]+e.cost;
                        if (i == V-1) return true;
                    }
                }
            }
            return false;
        }
        ll operator[](ll a){
            return d[a];
        }
};
vector<vector<ll>> g(2510);
vector<bool> done(2510,0);
void dfs(ll v){
    done[v] = true;
    for (ll u:g[v]){
        if (done[u]) continue;
        dfs(u);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,v,e;
    cin >> v >> e;
    vector<vector<ll>> graph(e,vector<ll>(3));
    rep(i,e){
        cin >> a >> b >> c;
        c *= -1;
        --a;
        --b;
        g[b].push_back(a);
        graph[i] = {a,b,c};
    }
    dfs(v-1);
    vector<Edge> ng;
    rep(i,e){
        if (done[graph[i][0]] && done[graph[i][1]]){
            ng.push_back(Edge{graph[i][0],graph[i][1],graph[i][2]});
        }
    }
    Bellman_Ford solve(ng,v);
    if (solve.bellman_ford(0)) PRINT("inf");
    else PRINT(-solve[v-1]);
}
