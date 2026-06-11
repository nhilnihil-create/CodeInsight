#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll fact(int n)
{
    return n == 1 ? 1 : (n * fact(n - 1)) % (1000000007);
}
int main()
{
    int n, m;
    cin >> n >> m;
    ll ans;

    if (n == m)
    {
        // cout << fact(n) * fact(m) << endl;
        ans = ((fact(n) * fact(m)) * 2) % 1000000007;
    }
    else if (abs(n - m) == 1)
    {
        ans = (fact(n) * fact(m)) % 1000000007;
    }
    else
    {
        ans = 0;
    }
    cout << ans << endl;

    return 0;
}
