#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m), ck(m, 0);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    rep(i, n)
    {
        ll dis = 1001001001001001001;
        int idx;
        rep(j, m)
        {
            ll tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dis > tmp && !ck[j])
            {
                dis = tmp;
                idx = j;
            }
        }
        cout << idx + 1 << endl;
    }

    return 0;
}
