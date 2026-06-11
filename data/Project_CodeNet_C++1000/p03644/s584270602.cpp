#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, maxn = 0, maxcnt = 0, cnt, tempi;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        tempi = i;
        while (tempi % 2 == 0)
        {
            tempi /= 2;
            cnt++;
        }
        if (cnt > maxcnt)
        {
            maxn = i;
            maxcnt = cnt;
        }
    }
    cout << maxn << endl;
    return 0;
}