#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define fi first
#define se second
#define MP make_pair

int read()
{
    int v = 0, f = 1;
    char c = getchar();
    while (c < 48 || 57 < c) {if (c == '-') f = -1; c = getchar();}
    while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
    return v * f;
}

int n, a[101000];

bool work()
{
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > 1)
            if (a[i] & 1)
                x++;
            else
                y++;
    if (y & 1)
        return 1;
    if (x >= 2 || x == 0)
        return 0;
    int g = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > 1)
        {
            if (a[i] & 1)
                a[i]--;
            g = __gcd(g, a[i]);
        }
    for (int i = 1; i <= n; i++)
        if (a[i] > 1)
            a[i] /= g;
    return !work();
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    printf(work() ? "First" : "Second");
}
