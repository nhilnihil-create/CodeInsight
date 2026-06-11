#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    auto ok = [&](int x, int y)
    {
        return x < n && y < a[x];
    };
    int x = 0, y = 0;
    while (ok(x + 1, y + 1))
    {
        x++, y++;
    }
    int la = 0, lb = 0;
    {
        int len = 1;
        int dx = x, dy = y;
        while (ok(dx, dy))
        {
            dx++;
            len ^= 1;
        }
        la = len;
    }
    {
        int len = 1;
        int dx = x, dy = y;
        while (ok(dx, dy))
        {
            dy++;
            len ^= 1;
        }
        lb = len;
    }
    if (la || lb)
    {
        cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }
}
