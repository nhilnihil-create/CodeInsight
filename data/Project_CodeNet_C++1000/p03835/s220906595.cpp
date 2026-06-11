#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll K, S; cin >> K >> S;

    ll ans = 0;
    for (ll x = 0; x <= K; ++x) {
        for (ll y = 0; y <= K; ++y) {
            ll z = S - x - y;
            if (z >= 0 && z <= K) ans++;
        }
    }
    cout << ans << endl;

}
