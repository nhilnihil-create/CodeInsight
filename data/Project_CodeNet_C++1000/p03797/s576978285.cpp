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

ll n, m, ans;

int main()
{
    sf("%lld%lld", &n, &m);
    if (n * 2 > m) {
        pf("%lld\n", m/2);
    }
    else {
        ans = n;
        m -= (n * 2);
        ans += (m/4);
        pf("%lld\n", ans);
    }
    return 0;
}
