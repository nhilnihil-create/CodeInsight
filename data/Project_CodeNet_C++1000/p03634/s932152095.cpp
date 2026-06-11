#include <bits/stdc++.h>
// #pragma GCC optimize("O3")

#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ std::cerr << std::endl; for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
vector<vector<tuple<ll,ll>>> g;
ll q,k;

vector<ll> mem;

void dfs(ll from, ll to, ll d){
    mem[to] = d;
    for(tuple<ll,ll> x : g[to]){
        ll p,cost;
        tie(p, cost) = x;
        if(p == from) continue;
        dfs(to, p, d+cost);
    }

}

int main(){
    cin >> n;
    g = vector<vector<tuple<ll,ll>>>(n+1);
    for(ll i = 0;i < n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(make_tuple(b, c));
        g[b].push_back(make_tuple(a, c));
    }
    cin >> q >> k;
    mem = vector<ll>(n+1);
    dfs(0, k, 0);
    for(ll i = 0;i < q;i++){
        ll x,y;
        cin >> x >> y;
        cout << mem[x] + mem[y] << endl;
    }
}
