/*+lmake
 * STD = c++14
 * DEFINE += WAAUTOMATON
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#ifdef WAAUTOMATON
#define debug(args...)                                                                             \
    {                                                                                              \
        dbg, args;                                                                                 \
        cerr << endl;                                                                              \
    }
#define massert(x) assert(x)
#else
#define debug(args...) // Just strip off all debug tokens
#define massert(x)
#endif
struct debugger
{
    template <typename T>
    debugger &operator,(const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;
const int maxn = 100000;
int pre[maxn + 10];
int a[maxn + 10];
void solve(long long n, long long l, long long t, vector<long long> x, vector<long long> w)
{
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (w[i] == 1) {
            a[i] = (x[i] + t) % l;
            cur += (x[i] + t) / l;
        } else if (w[i] == 2) {
            a[i] = (x[i] - t) % l;
            cur += (x[i] - t) / l;
            if (a[i] < 0) {
                a[i] += l;
                cur--;
            }
        }
    }
    cur = (cur % n + n) % n;
    sort(a, a + n);
    for (int i = cur; i < n; ++i) {
        printf("%d\n", a[i]);
    }
    for (int i = 0; i < cur; ++i) {
        printf("%d\n", a[i]);
    }
}

int main()
{
#ifdef WAAUTOMATON
    // freopen("in.txt","r",stdin);
#endif
    long long L;
    long long T;
    long long N;
    scanf("%lld", &N);
    vector<long long> W(N - 1 + 1);
    vector<long long> X(N - 1 + 1);
    scanf("%lld", &L);
    scanf("%lld", &T);
    for (int i = 0; i <= N - 1; i++) {
        scanf("%lld", &X[i]);
        scanf("%lld", &W[i]);
    }
    solve(N, L, T, X, W);
    return 0;
}
