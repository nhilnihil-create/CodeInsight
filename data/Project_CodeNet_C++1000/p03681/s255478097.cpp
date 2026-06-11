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

int i;
ll n, m;

int fact(ll x)
{
    if (x == 1) return 1;
    return (x * fact(x-1)) % 1000000007;
}

int main()
{
    sf("%lld%lld", &n, &m);
    if (abs(n-m) == 1) {
        ll n1 = 1, m1 = 1;
        for (i = 1; i <= n; i++) {
            n1 = (n1 * i) % 1000000007;
        }
        for (i = 1; i <= m; i++) {
            m1 = (m1 * i) % 1000000007;
        }
        pf("%d\n", (n1 * m1) % 1000000007);
    }
    else if (n == m) {
        ll n1 = 1;
        for (i = 1; i <= n; i++) {
            n1 = (n1 * i) % 1000000007;
        }
        pf("%d\n", (2 * n1 * n1) % 1000000007);
    }
    else {
        pf("0\n");
    }
    return 0;
}