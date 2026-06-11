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

int i, a[26];
string s;

int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++) {
        a[s[i]-'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (a[i] > 1) {
            pf("no\n");
            return 0;
        }
    }
    pf("yes\n");
    return 0;
}