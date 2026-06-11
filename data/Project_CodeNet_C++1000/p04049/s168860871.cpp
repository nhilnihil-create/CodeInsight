/*
 * Author       : YangDavid
 * Created Time : 2019年07月12日 星期五 10时47分11秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2222;
vector<int> G[maxn];
vector<pii> e;
int n, k, vis[maxn], rem;

void check_p(int v) {
    memset(vis, 0, sizeof(int) * (n + 10));
    queue<pii> q;
    vis[v] = true;
    q.emplace(v, 0);

    int mx = 0;
    while(!q.empty()) {
        auto f = q.front(); q.pop();
        for(auto g : G[f.first]) {
            if(f.second + 1 + mx > k) break;
            if(vis[g]) continue;
            q.emplace(g, f.second + 1);
            vis[g] = true;
            mx = max(mx, f.second + 1);
        }
    }

    int cnt = 0;
    rep(i, n) if(vis[i]) cnt++;
    rem = max(rem, cnt);
}

void check_e(int u, int v) {
    memset(vis, 0, sizeof(int) * (n + 10));
    queue<pii> q;
    
    int mx = 1, lim = k + 1, hf = lim / 2 + (lim & 1);
    q.emplace(u, 1), q.emplace(v, 1);
    vis[u] = vis[v] = true;

    while(!q.empty()) {
        auto f = q.front(); q.pop();
        for(auto g : G[f.first]) {
            if(f.second + 1 + mx > lim) break;
            if(vis[g]) continue;
            q.emplace(g, f.second + 1);
            vis[g] = true;
            mx = max(mx, f.second + 1);
        }
    }

    int cnt = 0;
    rep(i, n) if(vis[i]) cnt++;
    rem = max(rem, cnt);
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        e.emplace_back(u, v);
    }
    rep(i, n) check_p(i);
    for(auto g : e) 
        check_e(g.first, g.second);
    printf("%d\n", n - rem);

    return 0;
}
