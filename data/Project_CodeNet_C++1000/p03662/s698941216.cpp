#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
static const int MAX_N = 1e5;
int N;
vector<int> g[MAX_N];
int dist[2][MAX_N], id;

// parは初期値のときに弾く
void dfs(int idx, int par = -1)
{
    if (~par) { // par=-1のときはfalse
        dist[id][idx] = dist[id][par] + 1;
    }
    for (auto to : g[idx]) {
        if (to != par) {
            dfs(to, idx);
        }
    }
}

signed
main()
{
    cin >> N;
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    id = 0; // Fennec
    dfs(0);
    id = 1; // Snuke
    dfs(N - 1);
    int res = 0;
    rep(i, N)
    {
        if (dist[0][i] <= dist[1][i]) {
            ++res;
        }
    }
    if (res >= (N + 2) / 2) {
        puts("Fennec");
    } else {
        puts("Snuke");
    }
    return 0;
}