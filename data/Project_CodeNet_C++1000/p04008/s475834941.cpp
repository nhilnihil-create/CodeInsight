#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N, K;
int a[110000], h[110000];
pint p[110000];
vint rev[110000];
void dfs(int v, int ch) {
    if (h[v] < 0)return;
    h[v] = ch;
    for (int i = 0; i < rev[v].size(); i++)dfs(rev[v][i], ch + 1);
}
signed main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++)cin >> a[i];
    int ans = 0;
    if (a[1] != 1)a[1] = 1, ans++;
    for (int i = 2; i <= N; i++)rev[a[i]].push_back(i);
    dfs(1, 0);
    for (int i = 2; i <= N; i++)p[i] = pint(h[i], i);
    sort(p + 2, p + N + 1), reverse(p + 2, p + N + 1);
    for (int i = 2; i <= N; i++) {
        int cur = p[i].second;
        if (h[cur] <= K)continue;
        for (int j = 0; j < K - 1; j++)cur = a[cur];
        dfs(cur, LLONG_MIN);
        ans++;
    }
    cout << ans << endl;
}
