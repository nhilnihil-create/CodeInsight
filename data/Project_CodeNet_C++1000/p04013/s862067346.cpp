#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

ll dp[55][5300][55]; // [i番目までの累積][合計がJ][k枚使っている]

int main()
{
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n);

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1; // 初期化
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5200; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                // i番目のものを使う場合
                dp[i + 1][j + x[i]][k + 1] += dp[i][j][k];
                // i番目のものを使わない場合
                dp[i + 1][j][k] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    for (int k = 1; k <= n; k++)
    {
        ans += dp[n][a * k][k];
    }
    cout << ans << endl;
    return 0;
}
