#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second
#define int long long

int n;
int a[500000];
int kek = 1, ans = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (kek == 1)
        {
            ans += a[i] - 1;
            kek = 2;
            continue;
        }
        if (a[i] % kek == 0)
        {
            if (a[i] != kek)
            {
                a[i] -= kek + 1;
                ans++;
            }
            else
            {
                kek = a[i] + 1;
            }
        }
        if (a[i] % kek != 0)
        {
            int nw = a[i] % kek;
            ans += (a[i] - nw) / kek;
        }
    }
    cout << ans;
}