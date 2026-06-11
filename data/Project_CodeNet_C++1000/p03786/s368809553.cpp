#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int>
        a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            ans++;
            break;
        }
        cur += a[i];
        if (cur * 2 >= a[i + 1])
            ans++;
        else
            ans = 0;
    }
    cout << ans << endl;
    return 0;
}