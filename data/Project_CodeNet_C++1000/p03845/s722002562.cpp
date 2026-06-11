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

int i, n, a[100], m, p, x, s;

int main()
{
    sf("%d", &n);
    for (i = 0; i < n; i++) {
        sf("%d", &a[i]);
        s += a[i];
    }
    sf("%d", &m);
    while (m--) {
        sf("%d%d", &p, &x);
        pf("%d\n", s-a[p-1]+x);
    }
    return 0;
}