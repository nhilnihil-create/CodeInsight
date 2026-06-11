#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf (1LL<<60)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, M; cin >> N >> M;
    vll a(M), b(M), c(M);
    rep(i, M) cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--, c[i] = -c[i];

    vll dist(N, inf); dist[0] = 0;
    rep(_, N) rep(i, M) {
        if (dist[a[i]] == inf) continue;

        if (dist[b[i]] > dist[a[i]] + c[i]) dist[b[i]] = dist[a[i]] + c[i];
    }

    ll ans = dist[N-1];

    vector<bool> negative(N, false);
    rep(_, N) rep(i, M) {
        if (dist[a[i]] == inf) continue;

        if (dist[b[i]] > dist[a[i]] + c[i]) {
            negative[b[i]] = true;
            dist[b[i]] = dist[a[i]] + c[i];
        }

        if (negative[a[i]]) negative[b[i]] = true;
    }

    if (negative[N-1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}