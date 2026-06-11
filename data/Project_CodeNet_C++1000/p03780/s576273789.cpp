#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a, L=-1, R, t, g=1;
    cin >> n >> k;
    int D[k+1];
    vector <int> A;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    R = n;
    while (R - L > 1)
    {
        g = 0;
        t = (L + R) / 2;
        for (int i = 0; i <= k; i++)
        {
            D[i] = 0;
        }
        D[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != t)
            {
                for (int y = k-1; y >= 0; y--)
                {
                    if (A[i] + y < k && D[y] == 1)
                    {
                        D[y + A[i]] = 1;
                        if (y + A[i] >= k - A[t])
                        {
                            g = 1;
                        }
                    }
                }
            }
        }
        if (0 >= k - A[t])
        {
            g = 1;
        }
        if (g == 0)
        {
            L = t;
        }
        else
        {
            R = t;
        }
    }
    cout << L + 1;
    return 0;
}
