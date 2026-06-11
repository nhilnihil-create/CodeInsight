#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++)
    {
        int min_dist = 40000000000000;
        int min_indx;
        for (int j = 0; j < m; j++)
        {
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dist < min_dist)
            {
                min_indx = j;
                min_dist = dist;
            }
        }
        cout << min_indx + 1 << endl;
    }
    return 0;
}