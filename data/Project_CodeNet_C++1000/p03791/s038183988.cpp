#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int pos = 0;
    while (pos < n && 2 * pos + 1 <= x[pos])
    {
        pos++;
    }
    ll ret = (pos == n ? n : pos + 1);
    for (int i = 1; i < n; i++)
    {
        // i個処理済み
        while (pos < n && 2 * (pos - i) + 1 <= x[pos])
        {
            pos++;
        }
        ret *= (pos == n ? n - i : pos - i + 1);
        ret %= MOD;
    }
    cout << ret << endl;
}
