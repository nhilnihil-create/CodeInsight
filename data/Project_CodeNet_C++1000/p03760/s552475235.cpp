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

int i, j, k;
string a, b, s;

int main()
{
    cin >> a >> b;
    for (i = 0, j = 0, k = 1; ; k++) {
        if (i < a.size() && k % 2 == 1) {
            s += a[i];
            i++;
        }
        else if (j < b.size() && k % 2 == 0) {
            s += b[j];
            j++;
        }
        else {
            break;
        }
    }
    cout << s << endl;
    return 0;
}