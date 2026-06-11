#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 2005;

/* ...o(^-^)o... */

struct edge{
    int from, to; lint cost;
    edge(int f, int t, lint c) : from(f), to(t), cost(c) {}
    edge(int t, lint c) : from(-1), to(t), cost(c) {}
};
vector<edge> ve;

lint d[MAX];
int V, E;
void bellman_ford(int s){
    rep(i, V) d[i] = INF;
    d[s] = 0;
    rep(j, V - 1) rep(i, E){
        edge e = ve[i];
        if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
        }
    }
}

bool find_negloop(int s, int t){
    rep(i, V) d[i] = INF;
    d[s] = 0;
    rep(j, V - 1) rep(i, E){
        edge e = ve[i];
        if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
        }
    }
    bool neg[MAX];
    rep(i, V) neg[i] = false;
    rep(j, V) rep(i, E){
        edge e = ve[i];
        if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
            neg[e.to] = true;
        }
        if(neg[e.from]) neg[e.to] = true;
    }
    return neg[t];
}

bool find_negloop(){
    rep(i, V) d[i] = 0;
    rep(i, V) rep(j, E){
        edge e = ve[j];
        if(d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
            if(i == V - 1) return true;
        }
    }
    return false;
}

int main(){
    cin >> V >> E;
    rep(i, E){
        ii2(a, b); a--; b--;
        lint c; cin >> c;
        ve.push_back(edge(a, b, -c));
    }
    bool isneg = find_negloop(0, V-1);
    if(isneg){
        out("inf"); return 0;
    }
    bellman_ford(0);
    out(-d[V-1]);
}