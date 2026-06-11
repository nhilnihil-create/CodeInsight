#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;

int n;
pair<int, int> a[MaxN];
long long Res[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        Res[i] = 0;
    }
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    int Min = a[1].second;
    for (int i = 1; i <= n; i++)
    {
        Min = min(Min, a[i].second);
        Res[Min] += 1LL * (a[i].first - a[i + 1].first) * i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << Res[i] << '\n';
    }
    return 0;
}
