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

int i, a, b, c;
bool flag[101];

int main()
{
    sf("%d%d%d", &a, &b, &c);
    for (i = 0; ; i += a) {
        if ( (a + i) % b == c) {
            pf("YES\n");
            return 0;
        }
        else if (flag[(a + i) % b] == false) {
            flag[(a + i) % b] = true;
        }
        else {
            pf("NO\n");
            return 0;
        }
    }
    return 0;
}