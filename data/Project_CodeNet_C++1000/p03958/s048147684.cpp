#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    ll k, t;
    cin >> k >> t;
    ll ma = 0;
    ll sum = 0;
    rep(i, t)
    {
        ll a;
        cin >> a;
        sum += a;
        ma = max(a, ma);
    }

    ll ans = max((ll)0, 2 * ma - sum - 1);
    cout << ans << endl;
}