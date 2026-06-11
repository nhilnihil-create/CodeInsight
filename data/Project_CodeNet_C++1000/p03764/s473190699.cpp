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
    int xlosum = 0, ylosum = 0, xlensum = 0, ylensum = 0;
    for(int i = 0; i < n; i++)
    {
        xlensum += i * x[i] - xlosum;
        xlensum %= MOD;
        xlosum += x[i];
        xlosum %= MOD;
    }
    for(int i = 0; i < m; i++)
    {
        ylensum += i * y[i] - ylosum;
        ylensum %= MOD;
        ylosum += y[i];
        ylosum %= MOD;
    }
    cout << (xlensum * ylensum) % MOD << "\n";
    return 0;
}