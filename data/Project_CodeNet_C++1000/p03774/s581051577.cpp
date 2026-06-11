#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), x(m), y(m);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
    {
        int mind = 1e9, id = 0;
        for (int j = 0; j < m; j++)
        {
            if (abs(a[i] - x[j]) + abs(b[i] - y[j]) < mind)
            {
                mind = abs(a[i] - x[j]) + abs(b[i] - y[j]);
                id = j;
            }
        }
        cout << id + 1 << "\n";
    }
}
