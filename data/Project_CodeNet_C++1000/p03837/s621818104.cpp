#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
#define fst first
#define snd second
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1e9+7;

/* warshall_floyd(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、prev[i][j]にiからjへの最短路でのjの1つ前の点を格納
*/
void warshall_floyd(vector<vector<long long>> &dist, vector<vector<long long>> &prev) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }
}
 
/* get_path(prev, s, t)
    入力：warshall_floyd で得た prev, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(const vector<vector<long long>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    ll n, m; cin >> n >> m;
    vvll dist(n+1, vll(n+1, INF));
    vvll used(n+1, vll(n+1, INF));
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        used[a][b] = 0; used[b][a] = 0;
        dist[a][b] = c; dist[b][a] = c;
    }
    rep(i, 1, n+1){
        dist[i][i] = 0;
    }
    vvll prev(n+1, vll(n+1));
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            prev[i][j] = i;
        }
    }
    warshall_floyd(dist, prev);
    rep(i, 1, n+1){
        rep(j, i+1, n+1){
            vi g = get_path(prev, i, j);
            rep(k, 0, sz(g)-1){
                used[g[k]][g[k+1]] = 1;
                used[g[k+1]][g[k]] = 1;
            }
        }
    }
    ll ans = 0;
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(used[i][j] == 0){
                ans++;
            } 
        }
    }
    prtl(ans/2);
}
