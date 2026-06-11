#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0);

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cerr << dist[N-1] << endl;

    if (dist[N-1] <= 2 && dist[N-1] != -1) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}