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
using namespace std;

int i, j, n, a[100], ans, mn, mx;
vector<int>v;

int main()
{
    sf("%d", &n);
    for (i = 0; i < n; i++) {
        sf("%d", &a[i]);
    }
    mn = *min_element(a, a+n);
    mx = *max_element(a, a+n);
    for (j = mn; j <= mx; j++) {
        ans = 0;
        for (i = 0; i < n; i++) {
            ans += abs(a[i]-j) * abs(a[i]-j);
        }
        v.push_back(ans);
    }
    pf("%d\n", *min_element(v.begin(), v.end()));
    return 0;
}