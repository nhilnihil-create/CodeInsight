#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
long long sv[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    int prev;
    cin >> prev;
    prev--;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int cur;
        cin >> cur;
        cur--;
        ans += (cur - prev + m) % m;
        if ((cur - prev + m) % m >= 2)
        {
            int s = (prev + 2) % m;
            int t = cur;
            sv[s]++;
            if (s > t)
            {
                int k = m - s;
                sv[0] += k + 1;
                sv[1] -= k;
            }
            int x = (t - s + m + 1) % m;
            if (t + 1 < m)
                sv[t + 1] -= x + 1;
            if (t + 2 < m)
                sv[t + 2] += x;
        }
        prev = cur;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < m; j++)
        {
            sv[j] = sv[j] + sv[j - 1];
        }
    }
    long long bigSave = 0;
    for (int i = 0; i < m; i++)
        bigSave = max(bigSave, sv[i]);
    cout << ans - bigSave << endl;
    return 0;
}
