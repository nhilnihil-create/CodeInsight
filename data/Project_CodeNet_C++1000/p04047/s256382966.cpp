#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, sol = 0;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n; i += 2)
    {
        sol += a[i];
    }
    cout << sol << "\n";
}
