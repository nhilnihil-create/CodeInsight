#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> X(n);
    rep(i, n) cin >> X[i];
    ll ans = 0;
    rep(i, n - 1)
    {
        if ((X[i + 1] - X[i]) * a <= b)
            ans += (X[i + 1] - X[i]) * a;
        else
            ans += b;
    }
    cout << ans << endl;
}