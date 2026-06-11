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
vector<int> num;

int main()
{
    constexpr int m = 1e5 + 1;
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    num.assign(m, 0);
    for (int i = 0; i < n; ++i)
    {
        ++num[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = num[a[i]];
        if (a[i] > 0) cnt += num[a[i] - 1];
        if (a[i] < m - 1) cnt += num[a[i] + 1];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
