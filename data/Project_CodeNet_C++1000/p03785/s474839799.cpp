#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> T(n);
    rep(i, n) cin >> T[i];

    sort(T.begin(), T.end());
    ll ans = 1, z = 0, v; //バスの数と客の人数と今のバスの一人目の乗客の乗車時間
    rep(i, n)
    {
        if (i == 0)
            v = T[i];
        if (z == c)
        {
            ans++;
            v = T[i];
            z = 1;
            continue;
        }
        if (v + k < T[i])
        {
            ans++;
            v = T[i];
            z = 1;
            continue;
        }
        z++;
    }
    cout << ans << endl;
}