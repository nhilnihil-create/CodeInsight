#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N, x;
    cin >> N >> x;

    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);

    ll ans = 0;
    if (a.at(0) > x)
    {
        ans += a.at(0) - x;
        a.at(0) = x;
    }

    for (int i = 1; i < N - 1; i++)
    {
        if (a.at(i) + a.at(i - 1) > x)
        {
            ans += a.at(i) + a.at(i - 1) - x;
            a.at(i) = x - a.at(i - 1);
        }
    }

    if (a.at(N - 1) + a.at(N - 2) > x)
    {
        ans += a.at(N - 1) + a.at(N - 2) - x;
    }

    cout << ans << endl;
    return 0;
}