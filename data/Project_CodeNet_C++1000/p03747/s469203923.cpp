#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 端点を間違えないように気をつけること!
#define FOR(i, m, n) for (ll i = (ll)(m); i <= (ll)(n); i++)
#define RFOR(i, m, n) for (ll i = (ll)(m); i >= (ll)(n); i--)
ll amari(ll a, ll b)
{
    if (a >= 0)
    {
        return a % b;
    }
    else
    {
        ll c = (-a) % b;
        return (b - c) % b;
    }
}

int main()
{
    ll N, L, T, t_1, t_2, kijun = 0;
    cin >> N >> L >> T;
    t_1 = (T / L) % N;
    t_2 = T % L;
    ll X[N], W[N];
    vector<ll> Y;
    FOR(i, 0, N - 1)
    {
        cin >> X[i] >> W[i];
        if (W[i] == 1)
        {
            Y.push_back(amari(X[i] + T, L));
            kijun -= t_1;
            if (X[i] + t_2 >= L)
            {
                kijun--;
            }
        }
        else
        {
            Y.push_back(amari(X[i] - T, L));
            kijun += t_1;
            if (X[i] - t_2 < 0)
            {
                kijun++;
            }
        }
    }
    kijun = amari(kijun, N);
    sort(Y.begin(), Y.end());
    FOR(i, 0, N - 1)
    {
        if (i < kijun)
        {
            cout << Y[i + N - kijun] << endl;
        }
        else
        {
            cout << Y[i - kijun] << endl;
        }
    }
}