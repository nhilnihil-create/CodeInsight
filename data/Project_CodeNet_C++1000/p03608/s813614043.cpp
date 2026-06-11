#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

void dfs(vector<int>& perm, int state, int pre, ll sum, ll& ans,
         vector<vector<ll>>& adj) {
    if (state == (1 << perm.size())-1) {
        ans = min(ans, sum);
        return;
    }
    for(int i = 0; i < perm.size(); i++) {
        if (((state >> i) & 1) == 0) {
            state |= (1 << i);
            dfs(perm, state, perm[i], sum+adj[pre][perm[i]], ans, adj);
            state ^= (1 << i);
        }
    }
}

int main() {
    int n, m, r;
    int a, b, c;
    cin >> n >> m >> r;
    vector<vector<ll>> adj(n+1, vector<ll>(n+1, 1e7));
    vector<int> perm(r, 0);
    for(int& val: perm)
        cin >> val;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = min(adj[a][b], ll(c));
    }
    for(int i = 1; i <= n; i++)
        adj[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    ll ans = INT_MAX;
    int state = 0;
    for(int i = 0; i < perm.size(); i++) {
        state |= (1 << i);
        dfs(perm, state, perm[i], 0LL, ans, adj);
        state ^= (1 << i);
    }
    cout << ans << endl;
    return 0;
}


