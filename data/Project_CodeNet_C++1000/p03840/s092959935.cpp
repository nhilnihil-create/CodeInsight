#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define cases(t) for (int cas = 1; cas <= int(t); ++cas)
typedef long long ll;
typedef double db;
using namespace std;

#ifdef NO_ONLINE_JUDGE
#define LOG(args...) do { cout << #args << " -> "; err(args); } while (0)
void err() { cout << endl; }
template<typename T, typename... Args> void err(T a, Args... args) { cout << a << ' '; err(args...); }
#else
#define LOG(...)
#endif

ll i, o, t, j, l, s, z;

int main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &i, &o, &t, &j, &l, &s, &z);
    ll mn = min(i, min(j, l));
    ll ans1 = o * 2 + mn * 6;
    ans1 += (i - mn) / 2 * 4 + (j - mn) / 2 * 4 + (l - mn) / 2 * 4;
    mn = max(mn - 1, 0ll);
    ll ans2 = o * 2 + mn * 6;
    ans2 += (i - mn) / 2 * 4 + (j - mn) / 2 * 4 + (l - mn) / 2 * 4;
    printf("%lld\n", max(ans1, ans2) / 2);
    return 0;
}
