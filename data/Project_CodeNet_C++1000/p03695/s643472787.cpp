#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
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

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    vector<int> A;
    vector<int> color(9, 0);
    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
        int ind = A[i] / 400;
        if(ind > 8) { ind = 8; }
        color[ind]++;
    }

    int c_min = 0, c_max = 0;

    // 8 のみ
    bool eight = true;
    REP(i, 8) {
        if(color[i] > 0) {
            eight = false;
            break;
        }
    }
    if(eight && color[8] > 0) {
        c_min = 1;
    }
    else {
        REP(i, 8) {
            if(color[i] > 0) {
                c_min++;
                c_max++;
            }
        }
    }
    c_max += color[8];

    printf("%lld %lld\n", c_min, c_max);

    return 0;
}
