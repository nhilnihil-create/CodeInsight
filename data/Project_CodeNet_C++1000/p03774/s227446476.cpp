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

int i, j, n, m, min_index, mn;

int main()
{
    sf("%d%d", &n, &m);
    int a[n], b[n], c[m], d[m];
    for (i = 0; i < n; i++) {
        sf("%d%d", &a[i], &b[i]);
    }
    for (i = 0; i < m; i++) {
        sf("%d%d", &c[i], &d[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (j == 0) {
                min_index = 0;
                mn = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            }
            else if (abs(a[i]-c[j]) + abs(b[i]-d[j]) < mn) {
                mn = abs(a[i]-c[j]) + abs(b[i]-d[j]);
                min_index = j;
            }
        }
        pf("%d\n", min_index+1);
    }
    return 0;
}