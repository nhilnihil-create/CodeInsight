#include <bits/stdc++.h>
typedef long long ll;
ll x[100005];
ll y[100005];
int modd = 1e9 + 7;
ll ans,ansx,ansy;
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &x[i]);
    for (int i = 0; i < m; i++)
        scanf("%lld", &y[i]);
    for (ll i = 1; i < n; i++)
        ansx = (ansx + i * (n - i) % modd * (x[i] - x[i - 1]) % modd ) % modd;
    for (ll i = 1; i < m; i++)
        ansy = (ansy  + i * (m - i) % modd * (y[i] - y[i - 1]) % modd) % modd;
    ans = ansx * ansy % modd;
    printf("%lld\n", ans);
    return 0;
}