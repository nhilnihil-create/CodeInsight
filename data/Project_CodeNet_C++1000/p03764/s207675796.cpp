#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 1e5 + 5;

int n, m, x[maxn], y[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < m; i++)
        cin >> y[i];
    sort(x, x + n);
    sort(y, y + m);
    int xlensum = 0, ylensum = 0;
    for(int i = 0; i < n; i++)
    {
        xlensum += (i * x[i]) % MOD;
        xlensum -= ((n - 1 - i) * x[i]) % MOD;
        xlensum += MOD;
        xlensum %= MOD;
    }
    for(int i = 0; i < m; i++)
    {
        ylensum += (i * y[i]) % MOD;
        ylensum -= ((m - 1 - i) * y[i]) % MOD;
        ylensum += MOD;
        ylensum %= MOD;
    }
    cout << (xlensum * ylensum) % MOD << "\n";
    return 0;
}