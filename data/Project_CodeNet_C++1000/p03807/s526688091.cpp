#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2)
        {
            cnt++;
        }
    }

    cout << ((cnt % 2) ? "NO" : "YES") << '\n';
    return (0);
}
