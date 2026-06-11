#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x, y, v = 0;
    cin >> n >> k >> x >> y;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            v += x;
        else
            v += y;
    }
    cout << v;
}