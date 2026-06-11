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

int m[100][100];

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> c;
    rep(i, n) rep(j, a[i]) c.push_back(i + 1);

    int k = 0;
    rep(i, h)
    {
        bool flag = (i % 2 == 0 ? 0 : 1);
        int j = (flag == 0 ? 0 : w - 1);
        for (int cnt = 0; cnt < w; cnt++)
        {
            m[i][j] = c[k];
            k++;
            flag == 0 ? j++ : j--;
        }
    }

    rep(i, h) rep(j, w) j != w - 1 ? cout << m[i][j] << " " : OP(m[i][j]);

    return 0;
}