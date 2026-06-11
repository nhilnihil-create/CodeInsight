#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

int main()
{
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;
    vector <ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i < n; i++) {
        ll dist = (x[i] - x[i-1]);
        ans += min(dist*a, b);
    }
    cout << ans << endl;
    return 0;
}
