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

int n;
vector<int> a;
vector<int> G[100010];
bool ans = true;
int root = 0;

int dfs(int now, int pre){
    if(G[now].size() == 1) return a[now];
    int sum = 0;
    int cnt = 0, MAX = 0;
    rep(i, 0, G[now].size()){
        if(G[now][i] == pre) continue;
        int tmp = dfs(G[now][i], now);
        if(tmp > 0){
            sum += tmp;
            chmax(MAX, tmp);
            cnt++;
        }
    }
    if(pre == -1 && sum != 0 && a[now] != 0 && cnt < 2) ans = false;
    if(sum > 2 * a[now] || sum < a[now]) ans = false;
    if(a[now] < MAX) ans = false;
    return 2 * a[now] - sum;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n - 1){
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    if(n == 2){
        if(a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    rep(i, 0, n) if(G[i].size() != 1){root = i; break;}
    if(dfs(root, -1) != 0) ans = false;
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}