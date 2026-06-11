#include<bits/stdc++.h>
using namespace std;
inline void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
}
int main()
{
    io();
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int ans = numeric_limits<int>::max();
    for (int e = -100; e <= 100; ++e)
    {
        int cost = 0;
        for (int i = 0; i < n; ++i)
        {
            cost += (v[i] - e) * (v[i] - e);
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}
