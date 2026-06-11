#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 || b % 2 || c % 2)
    {
        cout << 0 << endl;
    }
    else if (a == b && b == c)
    {
        cout << -1 << endl;
    }
    else
    {
        int ans = 0;
        repi(i, INF, 0)
        {
            int tmp = a;
            a = b / 2 + c / 2;
            b = tmp / 2 + c / 2;
            c = tmp / 2 + (2 * a - c) / 2;
            ans++;
            if (a % 2 || b % 2 || c % 2)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}