#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<double> a(n), b(n), c(m), d(m);

    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, m)
    {
        cin >> c[i] >> d[i];
    }
    int ans = 0;
    double dis, mini;
    rep(i, n)
    {
        ans = 0;
        mini = fabs(a[i] - c[0]) + fabs(b[i] - d[0]);
        rep(j, m)
        {
            dis = fabs(a[i] - c[j]) + fabs(b[i] - d[j]);
            // cout << dis << endl;
            if (dis < mini)
            {
                ans = j;
            }
            mini = min(dis, mini);
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
