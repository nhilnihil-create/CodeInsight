#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<ll> que;
    que.push(0);
    vector<bool> visit(n, false);
    vector<ll> dist(n);

    while (que.size())
    {
        ll now = que.front();
        que.pop();
        visit[now] = true;

        for (auto next : G[now])
        {
            if (visit[next] == true)
                continue;

            dist[next] = dist[now] + 1;
            que.push(next);
        }
    }

    if (dist[n - 1] == 2)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}