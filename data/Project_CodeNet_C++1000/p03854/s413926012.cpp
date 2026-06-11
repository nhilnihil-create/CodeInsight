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

bool flag;
int i, pos;
string s, ara[] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
        cin >> s;
        reverse(s.begin(), s.end());
        for (i = 0; i < 4; i++) reverse(ara[i].begin(), ara[i].end());
        while (pos < s.size()) {
            flag = true;
            for (i = 0; i < 4; i++) {
                if (s.substr(pos, ara[i].size()) == ara[i]) {
                    pos += ara[i].size();
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) pf("NO\n");
        else pf("YES\n");
    
    return 0;
}