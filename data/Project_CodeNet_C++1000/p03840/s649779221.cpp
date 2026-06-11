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
const int MOD = 1000000007;
#define MAX_N 100010

int func(int ai, int ao, int aj, int al, int n) {
    int K = ao;
    // ai, aj, al のコンビぶんを加算
    REP(i, n) {
        if(ai > 0 && aj > 0 && al > 0) {
            K += 3;
            ai -= 1;
            aj -= 1;
            al -= 1;
        }
    }
    auto Add = [](int& k, int& a) {
        if(a % 2 == 0) {
            k += a;
            a = 0;
        } else {
            k += (a - 1);
            a = 1;
        }
    };
    Add(K, ai);
    Add(K, aj);
    Add(K, al);
    return K;
}

signed main()
{
    int ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    int K = func(ai, ao, aj, al, 0);
    K = max(K, func(ai, ao, aj, al, 1));

    printf("%lld\n", K);
    return 0;
}
