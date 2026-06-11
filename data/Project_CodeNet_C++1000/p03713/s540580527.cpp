#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010, mod = 1e9 + 7;

LL n, m;

LL solve(LL n, LL m)
{
    if(n % 3 == 0) return 0;
    LL res = (LL)m;
    for(int i = 1; i < n; i++)
    {
        LL v[] = {i * m, m / 2 * (n - i), (n - i) * (m - m / 2)};
        sort(v, v + 3);

        res = min(res, v[2] - v[0]);
    }
    return res;
}

int main()
{
    cin >> n >> m;

    cout << min(solve(n, m), solve(m, n)) << endl;
    return 0;
}
