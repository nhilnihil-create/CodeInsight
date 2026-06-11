#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver(ll *a, ll *b, ll N)
{
    ll cnt = 0;
    for (ll i = N - 1; i >= 0; --i)
    {
        if ((a[i] + cnt) % b[i])
        {
            cnt += b[i] - (a[i] + cnt) % b[i];
        }
    }
    return cnt;
}
int main()
{
    ll N;
    cin >> N;
    ll a[N], b[N];
    rep(i, 0, N) cin >> a[i] >> b[i];
    cout << solver(a, b, N) << endl;
}