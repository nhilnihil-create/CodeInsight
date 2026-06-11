#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> result(n);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                result[i] = a[n - 2 * i - 1];
            }
            else
            {
                result[i] = a[2 * i - n];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i <= n / 2)
            {
                result[i] = a[n - 2 * i - 1];
            }
            else
            {
                result[i] = a[2 * i - n];
            }
        }
    }
    cout << result[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << result[i];
    }
    cout << endl;
    return 0;
}
