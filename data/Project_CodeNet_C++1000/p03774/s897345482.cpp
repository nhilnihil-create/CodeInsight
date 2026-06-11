#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<ll> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < m; ++i) cin >> c[i] >> d[i];
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i)
    {
        ll dmin = 1 << 30;
        int ind = -1;
        for (int k = 0; k < m; ++k)
        {
            ll dis = abs(a[i] - c[k]) + abs(b[i] - d[k]);
            if (dmin > dis)
            {
                dmin = dis;
                ind = k + 1;
            }
        }
        res[i] = ind;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
