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
int i, j, n, f, b;
string x, s;

int main()
{
    sf("%d", &n);
    cin >> x;
    s = x;
    for (i = n-1; i >= 0; i--) {
        if (s[i] == '1') continue;
        else if (s[i] == '(') b++;
        else {
            flag = false;
            for (j = i-1; j >= 0; j--) {
                if (s[j] == '(') {
                    s[j] = '1';
                    flag = true;
                    break;
                }
            }
            if (flag == false) f++;
        }
    }
    s = "";
    while (f--) s += '(';
    s += x;
    while (b--) s += ')';
    cout << s << endl;
    return 0;
}