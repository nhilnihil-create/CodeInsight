#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


struct edge { ll from, to, cost; };
vector<edge> es; //辺の数でresize
vector<ll> d; //頂点の数でresize
int n, m; //頂点数と辺数
bool negative = false;

void bellmanford(int s) {
    rep(i,n) d[i] = LINF;
    d[s] = 0;
    rep(loop,n) {
        bool update = false;
        rep(i,m) {
            edge e = es[i];
            if (d[e.from] != LINF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
                //閉路検出
                if (loop == n-1 && e.to == n-1) {
                    negative = true;
                    break;
                }
            }
        }
        if (!update) break;
    }
}

//負の閉路検出（おまけ）
//trueなら負の閉路が存在
bool find_negative_loop() {
    rep(i,n) d[i] = 0;
    rep(i,n) {
        rep(j,m) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                //n回目にも更新があるなら負の閉路が存在
                if (i == n-1) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    d.resize(n);
    es.resize(m);
    rep(i,m) {
        edge e;
        cin >> e.from >> e.to >> e.cost;
        e.from--; e.to--;
        e.cost *= -1;
        es[i] = e;
    }
    // if (find_negative_loop()) {
    //     cout << "inf" << endl;
    //     return 0;
    // }
    bellmanford(0);
    if (negative) cout << "inf" << endl;
    else cout << -d[n-1] << endl;
}