#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (long long i = 0; i < (n); ++i)
#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    long long h, w;
    cin >> h >> w;
    long long minv = 1e16;
    for (long long i = 1; i < h; i++)
    {
        long long s[3];
        s[0] = i * w;

        // tate bunkatu
        s[1] = (w / 2) * (h - i);
        s[2] = h * w - s[0] - s[1];
        sort(s, s + 3);
        if (minv > s[2] - s[0])
            minv = s[2] - s[0];

        // yoko bunkatu
        if ((h - i) < 2)
            continue;
        s[0] = i * w;
        s[1] = w * ((h - i) / 2);
        s[2] = h * w - s[0] - s[1];
        sort(s, s + 3);
        if (minv > s[2] - s[0])
            minv = s[2] - s[0];
    }

    swap(h, w);
    for (long long i = 1; i < h; i++)
    {
        long long s[3];
        s[0] = i * w;

        // tate bunkatu
        s[1] = (w / 2) * (h - i);
        s[2] = h * w - s[0] - s[1];
        sort(s, s + 3);
        if (minv > s[2] - s[0])
            minv = s[2] - s[0];

        // yoko bunkatu
        if ((h - i) < 2)
            continue;
        s[0] = i * w;
        s[1] = w * ((h - i) / 2);
        s[2] = h * w - s[0] - s[1];
        sort(s, s + 3);
        if (minv > s[2] - s[0])
            minv = s[2] - s[0];
    }

    cout << minv << endl;
}