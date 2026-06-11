#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    int ans = 15;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int j = n / i;
        int k = i;
        int dj = 0;
        int di = 0;
        while(j) {
            j /= 10;
            dj++;
        }
        while(k) {
            k /= 10;
            di++;
        }
        ans = min(ans, max(dj, di));
    }
    cout << ans << endl;
    return 0;
}
