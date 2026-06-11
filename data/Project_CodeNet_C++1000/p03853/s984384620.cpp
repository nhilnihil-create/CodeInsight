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

int r, c;
string s[100];

int main()
{
    sf("%d%d", &r, &c);
    for (c = 0; c < r; c++) cin >> s[c];
    for (c = 0; c < r; c++) cout << s[c] << endl << s[c] << endl;
    return 0;
}