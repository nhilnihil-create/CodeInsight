#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

const int MAX_N = 2000;
int N, K;
vector<int> G[MAX_N];
int d[MAX_N][MAX_N];
pii e[MAX_N - 1];

void dfs(int v, int par, int root, int dist) {
    d[root][v] = dist;
    for (int c:G[v]) {
        if (c == par)continue;
        dfs(c, v, root, dist + 1);
    }
}

void distance() {
    rep(i, N) {
        dfs(i, -1, i, 0);
    }
}

signed main() {
    cin >> N >> K;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
        e[i] = pii(a, b);
    }
    distance();
    int ans = INF;
    if (K % 2 == 0) {
        rep(i, N) {
            int tmp = 0;
            rep(j, N) {
                if (d[i][j] > K / 2)tmp++;
            }
            ans = min(ans, tmp);
        }
    } else {
        rep(i, N - 1) {
            int a = e[i].first;
            int b = e[i].second;
            int tmp = 0;
            rep(j, N) {
                if (d[a][j] > (K - 1) / 2 && d[b][j] > (K - 1) / 2)tmp++;
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
