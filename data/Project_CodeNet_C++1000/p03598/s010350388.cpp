#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    REP(i, N) {
        ll xi;
        cin >> xi;

        if(xi < (double)K/2) {
            ans += 2*xi;
        } else {
            ans += 2*(K - xi);
        }
    }
    cout << ans << endl;

    return 0;
}