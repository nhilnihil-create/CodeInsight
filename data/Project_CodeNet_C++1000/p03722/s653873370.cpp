#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, M;
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;

    int a[MMAX], b[MMAX];
    ll c[MMAX];

    rep(i, M) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }

    ll dist[NMAX];

    rep(i, N) {
        dist[i] = inf;
    }

    dist[0] = 0;

    rep(loop, N) rep(i, M) {
        if (dist[a[i]-1] == inf) continue;

        if (dist[b[i]-1] > dist[a[i]-1] + c[i]) dist[b[i]-1] = dist[a[i]-1] + c[i];
    }

    ll ans = dist[N-1];

    bool negative[NMAX];

    rep(i, N) {
        negative[i] = false;
    }

    rep(loop, N) rep(i, M) {
        if (dist[a[i]-1] == inf) continue;

        if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
            dist[b[i]-1] = dist[a[i]-1] + c[i];
            negative[b[i]-1] = true;
        }

        if (negative[a[i]-1] == true) negative[b[i]-1] = true;
    }

    if (negative[N-1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}