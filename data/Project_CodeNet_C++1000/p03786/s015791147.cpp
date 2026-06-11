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
    int n;
    cin >> n;
    int a[n];
    repi(i, n, 0)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll cnt = 0, sum = 0, ans = 0;
    repi(i, n, 1)
    {
        sum += a[i - 1];
        cnt++;
        if (a[i] > sum * 2)
        {
            ans += cnt;
            cnt = 0;
        }
    }
    cout << n - ans << endl;
    return 0;
}