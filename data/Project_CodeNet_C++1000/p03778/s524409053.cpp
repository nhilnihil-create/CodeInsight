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

int w, a, b, a1, b1;

int main()
{
    sf("%d%d%d", &w, &a, &b);
    a1 = a + w;
    b1 = b + w;
    if (b >= a && b <= a1 || b1 >= a && b1 <= a1) pf("0\n");
    else {
        pf("%d\n", min(abs(a1-b), abs(a-b1)));
    }
    return 0;
}