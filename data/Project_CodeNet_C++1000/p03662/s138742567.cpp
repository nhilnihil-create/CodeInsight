#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

vector<int> G[200010];
int pr[200010];

void dfs(int now, int pre){
    pr[now] = pre;
    rep(i, 0, G[now].size()){
        int nxt = G[now][i];
        if(nxt == pre) continue;
        dfs(nxt, now);
    }
}
int cnt = 0;

void dfs2(int now, int pre){
    cnt++;
    rep(i, 0, G[now].size()){
        int nxt = G[now][i];
        if(nxt == pre) continue;
        dfs2(nxt, now);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    vector<int> path;
    int now = n - 1;
    path.push_back(now);
    while(now != 0){
        now = pr[now];
        path.push_back(now);
    }
    reverse(all(path));
    dfs2(path[(path.size() + 1) / 2 - 1], path[(path.size() + 1) / 2]);
    if(cnt > n - cnt) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}