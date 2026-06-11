#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> m;
    m.assign(h, vector<int>(w));

    int color = 0;
    rep(i, h) rep(j, w)
    {
        if (i % 2 == 0)
            m[i][j] = color + 1;
        else
            m[i][w - j - 1] = color + 1;
        --a[color];
        if (a[color] == 0)
            ++color;
    }

    rep(i, h) rep(j, w)
    {
        cout << m[i][j];
        if (j != w - 1)
            cout << " ";
        else
            cout << endl;
    }
}