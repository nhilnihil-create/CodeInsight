#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)

int dp[10001][101];

void solve()
{
    int K, T;
    cin >> K >> T;

    int sum = 0;
    int a_max = 0;
    REP0 (i, T)
    {
        int a;
        cin >> a;
        sum += a;
        a_max = max(a, a_max);
    }

    if (T == 1)
    {
        cout << sum - 1 << endl;
        return;
    }

    cout << max(0, a_max - (sum - a_max) - 1) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
