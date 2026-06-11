#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        mx = max(mx, a.at(i));
    }

    int g = a.at(0);
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, a.at(i));
    }

    if (k <= mx && k % g == 0)
    {
        cout << "POSSIBLE" << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}