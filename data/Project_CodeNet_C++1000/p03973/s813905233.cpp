#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    ll res = a[0] - 1, c = 2;
    for (int i = 1; i < N; i++)
    {
        if (a[i] == c)
        {
            c++;
            continue;
        }
        if (a[i] % c)
        {
            res += a[i] / c;
        }
        else
        {
            if (a[i] >= c + 1)
            {
                res += 1 + (a[i] - c - 1) / c;
            }
        }
    }
    cout << res << endl;
}
