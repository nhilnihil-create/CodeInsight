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

int i, sx, sy, tx, ty;
string s;

int main()
{
    sf("%d%d%d%d", &sx, &sy, &tx, &ty);
    for (i = sy; i < ty; i++) s += 'U';
    for (i = sx; i < tx; i++) s += 'R';
    for (i = ty; i > sy; i--) s += 'D';
    for (i = tx; i > sx; i--) s += 'L';
    s += 'L';
    for (i = sy; i < ty; i++) s += 'U';
    s += 'U';
    for (i = sx; i < tx; i++) s += 'R';
    s += 'R';
    s += 'D';
    s += 'R';
    for (i = ty; i > sy; i--) s += 'D';
    s += 'D';
    for (i = tx; i > sx; i--) s += 'L';
    s += 'L';
    s += 'U';
    cout << s << endl;
    return 0;
}