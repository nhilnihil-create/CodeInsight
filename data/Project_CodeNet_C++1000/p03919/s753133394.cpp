#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(ll i=0;i<n;++i)
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
#define MAX_N 30

template <typename T> T gcd(T a, T b) { while (a) { b %= a; swap(a, b); } return b; }
template <typename T> T lcm(T a, T b) { return a / gcd(a,b) * b; }

int H, W;
string S[MAX_N][MAX_N];
signed main()
{
    cin >> H >> W;
    int row = 1;
    char col = 'A';
    REP(i, H) {
        REP(j, W) {
            cin >> S[i][j];
            if(S[i][j] == "snuke") {
                row += i;
                col += j;
            }
        }
    }
    printf("%c%lld\n", col, row);
    return 0;
}
