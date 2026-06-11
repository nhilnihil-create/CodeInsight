#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;

    sort(ab.begin(), ab.end());
    const int ans = ab.back().first + ab.back().second;

    cout << ans << endl;
}
