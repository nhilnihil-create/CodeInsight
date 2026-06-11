#include <bits/stdc++.h>

using namespace std;

long long n, a[5000], minn[2001][2001];

int main()
{
    cin >> n;
    long long x;
    long long ans = 0;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans+=a[i];
        minn[i][i] = a[i];
        for (int j = i + 1; j < n; j++)
        {
            minn[i][j] = min(a[j], minn[i][j - 1]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        long long t = k * x;
        for (int i = 0; i < n; i++)
        {
            if (i - k >= 0)
            {
                t += minn[i - k][i];
            }
            else
            {
                t += min(minn[i - k + n][n - 1], minn[0][i]);
            }
        }
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}