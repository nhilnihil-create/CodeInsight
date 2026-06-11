#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repn(i,n) for(int i = 0; i <= (int)(n); i++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define srepn(i,l,n) for(int i = l; i <= (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define drepn(i,n) for(int i = (int)(l); i >= 0; i--)
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ep emplace_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

struct BellmanFord {
    struct edge{
        int from, to; ll cost;
    };
    int N, M;
    vector<edge> E;
    vector<ll> dis;
    const ll INF = 1e18;
    void DirectedInit(int n, int m) {
        N = n;
        M = m;
        E.resize(M);
        dis.assign(N, INF);
        for(int i = 0; i < M; i++) {
            int a, b; ll c;
            cin >> a >> b >> c;
            a--, b--;
            edge e = {a, b, c};
            E[i] = e;
        }
    }

    bool build(int s) {
        dis[s] = 0;
        bool update = false;
        for(int i = 0; i < N-1; i++) {
            update = false;
            for(int j = 0; j < M; j++) {
                edge e = E[j];
                int from = e.from;
                int to = e.to;
                ll cost = e.cost;
                if(dis[from] + cost < dis[to]) {
                    update = true;
                    dis[to] = dis[from] + cost;
                }
            }
            if(update && i == N-1) return true;
            if(!update) break;
        }
        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    BellmanFord g;
    g.DirectedInit(n, m);
    rep(i, m) {
        g.E[i].cost *= -1;
    }
    g.build(0);
    ll ans = g.dis[n-1];
    vector<bool> ng(n, false);
    rep(i, n) rep(j, m) {
        auto e = g.E[j];
        int from = e.from;
        int to = e.to;
        ll cost = e.cost;
        if(g.dis[from] == g.INF) continue;
        if(g.dis[from] + cost < g.dis[to]) {
            g.dis[to] = g.dis[from] + cost;
            ng[to] = true;
        }
        if(ng[from]) ng[to] = true;
    }
    if(ng[n-1]) cout << "inf" << endl;
    else cout << -ans << endl;
}
