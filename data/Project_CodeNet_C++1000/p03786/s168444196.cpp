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

void solve()
{
    int N;
    cin >> N;
    vector<LL> A(N);
    REP0 (i, N)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    vector<LL> cum(N);

    REP0 (i, N)
    {
        cum[i] = A[i];
        if (i != 0)
            cum[i] += cum[i - 1];
    }

    int ans = N;

    RREP0(i, N - 1)
    {
        if (cum[i] * 2 < A[i + 1])
        {
            ans -= (i + 1);
            break;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
