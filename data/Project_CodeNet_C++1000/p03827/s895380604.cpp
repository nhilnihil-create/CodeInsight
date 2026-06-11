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

int i, ans, x, n;
string s;

int main()
{
    sf("%d", &n);
    cin >> s;
    for (i = 0; i < n; i++) {
        if (s[i] == 'I') x++;
        else x--;
        if (x > ans) ans = x;
    }
    pf("%d\n", ans);
    return 0;
}