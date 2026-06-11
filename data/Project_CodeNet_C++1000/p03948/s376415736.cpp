#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

ll N, T;
ll A[MAX_N] = {};
ll MaxVal[MAX_N] = {};  // [i, N-1] の最大値

signed main()
{
    cin >> N >> T;
    REP(i, N) { cin >> A[i]; }

    ll cur = 0;
    ll max_sub = 0;
    for(int i = N-1; i >= 0; --i) {
        cur = max(cur, A[i]);
        MaxVal[i] = cur;
        max_sub = max(max_sub, MaxVal[i] - A[i]);
    }

    ll ans = 0;
    REP(i, N) {
        if(MaxVal[i] - A[i] == max_sub) { ans++; }
    }
    printf("%lld\n", ans);
    return 0;
}
