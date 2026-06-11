#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int main(void)
{
    int k, s;
    cin >> k >> s;
    double verify = s / (k * 3);
    if (verify >= 1)
    {
        if (verify == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int tmp = s - i - j;
            if (0 <= tmp && tmp <= k)
                ans += 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}