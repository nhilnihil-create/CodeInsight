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
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += v[i];
    }

    cout << ((s % 2) ? "NO" : "YES") << '\n';
    return (0);
}
