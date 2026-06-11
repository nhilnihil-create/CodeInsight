#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
        if (i < b.size()) cout << b[i];
    }
}
