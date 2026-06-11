#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2+10;
typedef long long ll;
ll a[maxn][maxn], n, m, ans;
ll cnt[maxn];
bool vis[maxn];
//ll st[maxn];

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j)
            scanf("%lld", &a[i][j]);
    }
    ans = n, vis[0] = 1;
    for (int k=1; k<=m; ++k) {
        memset(cnt, 0, sizeof(cnt));
        ll mx = -1, pos = 1;
        for (ll i=1; i<=n; ++i) {
            for (ll j=1; j<=m; ++j) {
                if(!vis[a[i][j]]) {
                    ++cnt[a[i][j]];
                    break;
                }
            }
        }
        for (int i=1; i<=m; ++i) if(mx<cnt[i]) mx=cnt[i], pos=i;
        vis[pos] = 1;
        ans = min(ans, mx);
    }
    printf("%lld\n", ans);
    return 0;
}
