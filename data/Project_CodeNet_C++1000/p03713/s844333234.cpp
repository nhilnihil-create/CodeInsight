#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll h, w;
    cin >> h >> w;

    ll minv = 1e12;
    for (int i = 1; i < w; i++)
    {
        if (i != w - 1)
            minv = min(minv, max({i * h, h * ((w - i) / 2), h * ((w - i) - (w - i) / 2)}) - min({i * h, h * ((w - i) / 2), h * ((w - i) - (w - i) / 2)}));
        minv = min(minv, max({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)}) - min({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)}));
    }

    swap(h, w);
    for (int i = 1; i < w; i++)
    {
        if (i != w - 1)
            minv = min(minv, max({i * h, h * ((w - i) / 2), h * ((w - i) - (w - i) / 2)}) - min({i * h, h * ((w - i) / 2), h * ((w - i) - (w - i) / 2)}));
        minv = min(minv, max({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)}) - min({i * h, (w - i) * (h / 2), (w - i) * (h - h / 2)}));
    }
    OP(minv);
    return 0;
}