#include <bits/stdc++.h>

using namespace std;

using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> per(n), cp(m);
    for (int i = 0; i < n; i++)
        cin >> per[i].first >> per[i].second;
    for (int i = 0; i < m; i++)
        cin >> cp[i].first >> cp[i].second;
    for (int i = 0; i < n; i++)
    {
        int mx = 1e9, ans = -1;
        for (int j = 0; j < m; j++)
        {
            int x = abs(per[i].first - cp[j].first);
            int y = abs(per[i].second - cp[j].second);
            if (mx > x + y)
            {
                ans = j + 1;
                mx = x + y;
            }
        }
        cout << ans << endl;
    }
    return 0;
}