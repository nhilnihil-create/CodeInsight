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

int main()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int st = n;
    for (int i = 1; i <= n; i++)
        if (a[i] < i)
        {
            st = i - 1;
            break;
        }
    bool u = 1, r = 1;
    u = (a[st] - st - 1) & 1;
    for (int i = st + 1; i <= n; i++)
        if (a[i] == st) r = !r;
    if (!u || !r) puts("First"); else puts("Second");
}
