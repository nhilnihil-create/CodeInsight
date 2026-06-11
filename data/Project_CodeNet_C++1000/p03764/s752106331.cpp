#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5;
int x[MAXN + 1];
int y[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= m; i++)
        cin >> y[i];
    int a, b;
    a = b = 0;
    for (int i = 2; i <= n; i++)
    {
        a = (int) ((a + (long long) (i - 1) * x[i]) % MOD);
    }
    for (int i = 1; i <= n; i++)
    {
        a = (int) ((a - ((long long) (n - i) * x[i]) % MOD + MOD) % MOD);
    }
    for (int i = 2; i <= m; i++)
    {
        b = (int) ((b + (long long) (i - 1) * y[i]) % MOD);
    }
    for (int i = 1; i <= m; i++)
    {
        b = (int) ((b - ((long long) (m - i) * y[i]) % MOD + MOD) % MOD);
    }
    cout << (long long) a * b % MOD << endl;
    return 0;
}
