#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n - 1, 0);
    if (n == 2)
    {
        if (x == 2)
        {
            cout << "Yes" << endl;
            cout << "1 2 3" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return 0;
    }
    if (x == 1 || x == 2 * n - 1)
    {
        cout << "No" << endl;
        return 0;
    }
    if (x == 2 || x == 2 * n - 2)
    {
        cout << "Yes" << endl;
        if (x == 2 * n - 2)
        {
            a[n - 1] = x;
            a[n - 2] = x - 1;
            a[n - 3] = x - 2;
            a[n] = x + 1;
            a[n + 1] = x - 3;
            int k = 1;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == 0)
                {
                    a[i] = k;
                    k++;
                }
            }
        }
        if (x == 2)
        {
            a[n - 1] = 2;
            a[n - 2] = 1;
            a[n - 3] = 5;
            a[n] = 4;
            a[n + 1] = 3;
            int k = 6;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == 0)
                {
                    a[i] = k;
                    k++;
                }
            }
        }
        for (auto e : a)
        {
            cout << e << endl;
        }
        return 0;
    }
    cout << "Yes" << endl;
    a[n - 1] = x;
    a[n - 2] = x - 1;
    a[n] = x + 1;
    a[n + 1] = x - 2;
    int k = 1;
    if (x == 3)
    {
        k = 5;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            a[i] = k;
            k++;
            if (k == x - 2)
            {
                k = x + 2;
            }
        }
    }
    for (auto e : a)
    {
        cout << e << endl;
    }
}
