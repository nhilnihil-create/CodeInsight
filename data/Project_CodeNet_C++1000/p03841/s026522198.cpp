#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int x[N], y[N];
int a[N * N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> x[i];
    for (int i = 1; i <= n; i ++) y[i] = i;
    sort(y + 1, y + n + 1, [](int l, int r) {return x[l] < x[r];});
    int p = 1;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j < y[i]; j ++)
        {
            if (p >= x[y[i]])
            {
                cout << "No" << endl;
                return 0;
            }
            a[p] = y[i];
            while (a[p]) p ++;
        }
        a[x[y[i]]] = y[i];
        while (a[p]) p ++;
    }
    p = n * n;
    while (a[p]) p --;
    for (int i = n; i > 0; i --)
    {
        for (int j = 1; j <= n - y[i]; j ++)
        {
            if (p <= x[y[i]])
            {
                cout << "No" << endl;
                return 0;
            }
            a[p] = y[i];
            while (a[p]) p --;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n * n; i ++)
        cout << a[i] << ' ';
}