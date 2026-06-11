#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int arr[100010];

long long a[200010];
long long b[200010];
long long res[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long r = 0;
    for(i = 0; i < n - 1; i++)
    {
        int x = arr[i];
        int y = arr[i + 1];
        x--;
        y--;

        if(y < x)
            y += m;

        r += y - x;

        a[x + 1] += 1;
        b[x + 1] += -(x + 1);

        a[y + 1] -= 1;
        b[y + 1] -= -(x + 1);
    }

    long long p = 0, q = 0;
    for(i = 0; i < 2 * m; i++)
    {
        p += a[i];
        q += b[i];
        res[i % m] += p * i + q;
    }

    r -= *max_element(res, res + m);

    printf("%lld\n", r);
    return 0;
}