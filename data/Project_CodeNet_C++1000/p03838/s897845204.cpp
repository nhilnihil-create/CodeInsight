# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ll x, y; cin >> x >> y;
    
    ll ans = 1e18;
    if (x <= y) ans = min(ans, y - x);
    if (-x <= y) ans = min(ans, y + x + 1);
    if (x <= -y) ans = min(ans, - y - x + 1);
    if (-x <= -y) ans = min(ans, - y + x + 2);

    cout << ans << endl;
}