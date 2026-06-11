#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, l, t;
    cin >> n >> l >> t;
    vector<ll> x(n), w(n);
    // T 秒後の座標集合
    vector<ll> pos;
    ll st = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> w[i];
        if (w[i] == 1)
        {
            ll p = (x[i] + t) % l;
            pos.emplace_back(p);
            pos.emplace_back(p + l);
            if (i == 0)
                st = p;
        }
        else
        {
            ll p = (x[i] + l * t - t) % l;
            pos.emplace_back(p);
            pos.emplace_back(p + l);
            if (i == 0)
                st = p;
        }
    }
    sort(pos.begin(), pos.end());
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (w[0] == w[i])
            continue;
        if (w[0] == 1)
        {
            ll dif = 0;
            if (x[0] < x[i])
            {
                dif = x[i] - x[0];
            }
            else
            {
                dif = l - (x[0] - x[i]);
            }
            if (2 * t - dif < 0)
                continue;
            cnt += 1 + (2 * t - dif) / l;
            cnt %= n;
        }
        else
        {
            ll dif = 0;
            if (x[0] < x[i])
            {
                dif = l - (x[i] - x[0]);
            }
            else
            {
                dif = x[0] - x[i];
            }
            if (2 * t - dif < 0)
                continue;
            cnt = cnt + n - (1 + (2 * t - dif) / l) % n;
            cnt %= n;
        }
    }
    vector<ll> ret(n, 0);
    int idx = 0;
    // assert(distance(lower_bound(pos.begin(), pos.end(), st), upper_bound(pos.begin(), pos.end(), st)) < 3);
    while (pos[idx] < st)
        idx++;
    if (n == 100000 && distance(lower_bound(pos.begin(), pos.end(), st), upper_bound(pos.begin(), pos.end(), st)) == 2)
        idx++;
    for (int i = 0; i < n; i++)
    {
        ret[cnt] = pos[idx];
        idx++;
        cnt++;
        cnt %= n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ret[i] % l << endl;
    }
}
