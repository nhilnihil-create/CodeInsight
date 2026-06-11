#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

int n, k;
int a[100000];
vector<int> e[100000];
int ans = 0;
P dist[100000];
bool done[100000];

void dfs(int v, int d) {
    rep(i,e[v].size()) {
        dist[e[v][i]] = P(d+1, e[v][i]);
        dfs(e[v][i], d+1);
    }
}

void paint(int v) {
    if (done[v]) return;
    done[v] = true;
    rep(i,e[v].size()) {
        paint(e[v][i]);
    }
}

int main() {
    cin >> n >> k;
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        if (i == 0) {
            if (a[0] != 0)  {
                a[0] = 0;
                ans++;
            }
        } else {
            e[a[i]].push_back(i);
        }
    }
    done[0] = true;
    dist[0] = P(0, 0);
    dfs(0, 0);
    sort(dist, dist+n, greater<P>());
    rep(i,n) {
        if (done[dist[i].second]) continue;
        if (dist[i].first <= k) continue;
        ans++;
        int now = dist[i].second;
        rep(j,k-1) {
            now = a[now];
        }
        paint(now);
    }
    cout << ans << endl;
}






























