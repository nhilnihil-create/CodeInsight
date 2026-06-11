#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100010

ll N, M;
ll X[MAX_N] = {};
ll Y[MAX_N] = {};

int main()
{
    cin >> N >> M;
    REP(i, N) { cin >> X[i]; }
    REP(i, M) { cin >> Y[i]; }

    // 部分線の全パターンを足したもの
    ll ans_x = 0, ans_y = 0;
    REP(i, N) {
        ans_x = (ans_x + (X[i] * i)) % MOD;
        ans_x = (ans_x - (X[i] * (N - 1 - i)) + MOD) % MOD;
    }
    REP(i, M) {
        ans_y = (ans_y + (Y[i] * i)) % MOD;
        ans_y = (ans_y - (Y[i] * (M - 1 - i)) + MOD) % MOD;
    }
    printf("%lld\n", (ans_x * ans_y) % MOD);
    return 0;
}
