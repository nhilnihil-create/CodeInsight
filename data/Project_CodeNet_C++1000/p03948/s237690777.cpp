#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;


int main()
{
    int n, t;
    cin >> n >> t;
    int a, minn = inf, maxn = 0;
    int diff[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        diff[i] = max(a - minn, 0);
        minn = min(a, minn);
        maxn = max(diff[i], maxn);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (diff[i] == maxn)
            ans++;
    cout << ans << endl;
    return 0;
}