#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (x == 2)
        {
            cout << i << endl;
            return 0;
        }
        x = a[x];
    }
    cout << -1 << endl;
    return 0;
}