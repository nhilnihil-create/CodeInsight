#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int j = 0, p = 0;
    bool f = false;
    for (int i = 1; i <= n; i++)
    {
        if (j == 2)
        {
            f = true;
            break;
        }
        if (j == 0)
        {
            j = a[i];
            p++;
        }
        else
        {
            j = a[j];
            p++;
        }
    }
    if (f)
        cout << p << endl;
    else
        cout << -1 << endl;
}
