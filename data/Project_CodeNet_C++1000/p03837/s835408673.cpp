#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void allcout(auto V) {
    for(auto x : V) cout << x << ' ';
    cout << endl;
}
signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, -1));
    vector<vector<int>> dis(N, vector<int>(N, INF));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    rep(k, N) rep(i, N) rep(j, N) {
        chmin(dis[i][j], dis[i][k] + dis[k][j]);
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++) {
            if(G[i][j] == -1) continue;
            if(G[i][j] > dis[i][j]) ans++;
        }
    cout << ans << endl;
}
