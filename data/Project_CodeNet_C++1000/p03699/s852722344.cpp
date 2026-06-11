#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <stack>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <sstream>
#define popcount(x) __builtin_popcount(x)
#define oddparity(x) __builtin_parity(x)
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;

int i, ans, n, a[100];

int main()
{
    sf("%d", &n);
    for (i = 0; i < n; i++) {
        sf("%d", &a[i]);
        ans += a[i];
    }
    if (ans % 10 == 0) {
        sort(a, a + n);
        for (i = 0; i < n; i++) {
            if (a[i] % 10 != 0) {
                ans -= a[i];
                pf("%d\n", ans);
                return 0;
            }
        }
        pf("0\n");
        return 0;
    }
    pf("%d\n", ans);
    return 0;
}