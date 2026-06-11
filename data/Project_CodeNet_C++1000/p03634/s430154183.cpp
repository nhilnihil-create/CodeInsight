#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

// dijkstra
struct edge{int to; ll cost;};

struct dijkstra {
    int V;
    vll d;
    vector<vector<edge>> G;

    dijkstra(int n) {init(n);} 

    void init(int n) {
        V = n;
        G.resize(V);
        d.resize(V);
        rep(i,V) d[i] = inf_l;
    }

    void add_edge(int s, int t, ll cost) {
        s--; t--;
        edge e;
        e.to = t; e.cost = cost;
        G[s].push_back(e);
    }

    void run(int s) {
        s--;
        priority_queue<P, vector<P>, greater<P>> q;
        d[s] = 0;
        q.push(P(0,s));
        while (!q.empty()) {
            P p = q.top(); q.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (auto e: G[v]) {
                if (chmin(d[e.to],d[v]+e.cost)) {
                    q.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

int main() {
    int n; cin >> n;
    dijkstra dj(n);
    rep(i,n-1) {
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        dj.add_edge(a,b,c);
        dj.add_edge(b,a,c);
    }
    int q, k; cin >> q >> k;
    dj.run(k);
    rep(i,q) {
        int x, y; cin >> x >> y;
        x--; y--;
        cout << dj.d[x] + dj.d[y] << endl;
    }
}