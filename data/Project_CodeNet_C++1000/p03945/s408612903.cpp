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

int i;
string s, x;

int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++) {
        if (i == 0) x += s[i];
        else if (s[i] != x[x.size()-1]) x += s[i];
    }
    pf("%d\n", x.size()-1);
    return 0;
}