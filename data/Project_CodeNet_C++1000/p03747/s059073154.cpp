#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll X[100010];
ll W[100010];
ll tmp[100010]; //T秒後の位置, いんでっくす

ll ans[100010];

ll calc_count(ll x, ll y, ll L, ll T)
{
    if (T * 2 < abs(x - y))
        return 0;
    ll remain = T * 2 - abs(x - y);
    return 1 + remain / L;
}
int main(void)
{
    ll N, L, T;
    cin >> N >> L >> T;

    for (int i = 0; i < N; ++i)
    {
        cin >> X[i] >> W[i];
    }
    for (int i = 0; i < N; ++i)
    {
        if (W[i] == 1)
        {
            tmp[i] = (X[i] + (T % L) + L) % L;
        }
        else
        {
            tmp[i] = (X[i] - (T % L) + L) % L;
        }
        //cout << tmp[i] << endl;
    }
    sort(tmp, tmp + N);
    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        if (W[i] == 1)
            count -= (T - (L - X[i]) + L) / L;
        else
            count += (T - (X[i] + 1) + L) / L;
    }
    count = (count % N + N) % N; //countは非負

    for (int i = 0; i < N; ++i)
    {
        ans[(i + count) % N] = tmp[i];
    }
    for (int i = 0; i < N; ++i)
        cout << ans[i] << endl;

    return 0;
}