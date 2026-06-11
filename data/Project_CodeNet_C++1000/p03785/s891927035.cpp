#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    int t[n];
    repi(i, n, 0)
    {
        cin >> t[i];
    }
    sort(t, t + n);
    int ans = 1, cnt = 0, limit = t[0] + k;
    repi(i, n, 0)
    {
        cnt++;
        if (cnt > c || t[i] > limit)
        {
            cnt = 1;
            limit = t[i] + k;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}