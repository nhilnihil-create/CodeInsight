#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        ll d = x[i + 1] - x[i];
        if (a * d > b)
            ans += b;
        else
            ans += a * d;
    }
    cout << ans << endl;
}
