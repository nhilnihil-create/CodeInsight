#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long n, k, a[500000];

int main()
{
    cin >> n >> k; for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    long long p = 0, s = 0, ss = 0;
    for (int i = k; i < n; i++) s += max(0LL, a[i]);
    for (int i = 0; i < k; i++) ss += a[i];
    ans = max(ans, p + max(0LL, ss) + s);
    for (int i = k; i < n; i++)
    {
        s -= max(0LL, a[i]);
        ss += a[i];
        p += max(0LL, a[i - k]);
        ss -= a[i - k];
        ans = max(ans, p + max(0LL, ss) + s);
    }
    cout << ans;
}
