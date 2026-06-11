#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, ans = 0;
    cin >> n >> t;
    int tarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tarr[i];
    }
    ans += t;
    for (int i = 1; i < n; i++)
    {
        ans += (t > tarr[i] - tarr[i - 1] ? tarr[i] - tarr[i - 1] : t);
    }

    cout << ans << endl;
    return 0;
}