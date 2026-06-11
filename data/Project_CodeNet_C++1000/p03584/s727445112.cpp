#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second

int n, k;
int a[500000];
long long b[500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    long long ans = 0;
    for (int i = 1; i < 31; i++)
    {
        if ((1 << i) & k)
        {
            int kek = k - (1 << i);
            kek |= (1 << i) - 1;
            long long s = 0;
            for (int j = 0; j < n; j++)
            {
                if ((kek | a[j]) == kek)
                {
                    s += b[j];
                }
            }
            ans = max(ans, s);
        }
    }
    int kek = k;
    long long s = 0;
    for (int j = 0; j < n; j++)
    {
        if ((kek | a[j]) == kek)
        {
            s += b[j];
        }
    }
    ans = max(ans, s);
    cout << ans;
}