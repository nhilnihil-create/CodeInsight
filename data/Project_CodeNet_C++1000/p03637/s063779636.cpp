#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d1 = 0, d2 = 0, d4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            d1++;
        if (a[i] % 2 == 0 && a[i] % 4 != 0)
            d2++;
        if (a[i] % 4 == 0)
            d4++;
    }
    if (d2)
    {
        cout << (d1 <= d4 ? "Yes" : "No") << endl;
    }
    else
    {
        cout << (d1 <= d4 + 1 ? "Yes" : "No") << endl;
    }
}