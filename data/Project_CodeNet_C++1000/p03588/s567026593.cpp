#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(ALL(p));
    ans = p[0].first;
    for (int i = 1; i < n; i++)
    {
        ans += min(p[i].first - p[i - 1].first, p[i - 1].second - p[i].second);
    }
    ans += p[n - 1].second;
    cout << ans << endl;
    return 0;
}
