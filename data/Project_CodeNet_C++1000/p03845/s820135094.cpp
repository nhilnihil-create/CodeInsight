#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> t(n, 0);
    int m;
    int t_sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> t[i];
        t_sum += t[i];
    }
    cin >> m;
    vector<pair<int, int>> vp;
    for (size_t i = 0; i < m; i++)
    {
        int p, x;
        cin >> p >> x;
        vp.push_back({p, x});
        /* code */
    }
    for (size_t i = 0; i < m; i++)
    {
        cout << t_sum - t[vp[i].first - 1] + vp[i].second << endl;
    }

    return 0;
}