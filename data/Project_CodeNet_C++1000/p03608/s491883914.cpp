#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

struct WarshallFloyd {
    int N;
    vector<vector<ll>> dis;
    void init(int n, int m) {
        N = n;
        dis.assign(n, vector<ll>(n, 1e18));
        for(int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int u, v, l;
            cin >> u >> v >> l;
            u--, v--;
            dis[u][v] = l;
            dis[v][u] = l;
        }
    }
    void build() {
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) {
                    chmin(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
    }
};


int main(){
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> t(r);
    for(int i = 0; i < r; i++) cin >> t[i], t[i]--;
    sort(t.begin(), t.end());
    WarshallFloyd g;
    g.init(n, m);
    g.build();

    ll ans = 1e18;

    do {
        ll now = 0;
        for(int i = 0; i < r-1; i++) {
            now += g.dis[t[i+1]][t[i]];
        }
        chmin(ans, now);
    }while(next_permutation(t.begin(), t.end()));

    cout << ans << endl;
}