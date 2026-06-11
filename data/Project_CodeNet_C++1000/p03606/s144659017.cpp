#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    repi(i, n, 0)
    {
        int l, r;
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;
    return 0;
}