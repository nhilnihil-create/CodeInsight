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
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll L, Q;
    cin >> L >> Q;
    // r[i][j] := ホテル i から 2^j 日で到達できる最右ホテル
    vector<vector<int>> r(n, vector<int>(20));
    for (int i = 0; i < n; i++)
    {
        auto itr = upper_bound(x.begin(), x.end(), x[i] + L);
        itr--;
        r[i][0] = distance(x.begin(), itr);
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i < n; i++)
            r[i][j] = r[r[i][j - 1]][j - 1];
    }
    while (Q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b)
            swap(a, b);
        int ret = 1;
        for (int i = 19; i >= 0; i--)
        {
            if (r[a][i] < b)
            {
                a = r[a][i];
                ret += 1 << i;
            }
        }
        cout << ret << endl;
    }
}
