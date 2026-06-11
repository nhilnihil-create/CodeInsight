#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    ll N, M;
    cin >> N >> M;

    ll nc = 1, mc = 1;

    for(ll i = N; i > 1; i--) {
        nc *= i;
        nc %= mod;
    }

    for(ll i = M; i > 1; i--) {
        mc *= i;
        mc %= mod;
    }

    if(N != M) {
        if(abs(N - M) == 1) {
            ll ans = nc * mc;
            ans %= mod;
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        ll ans = nc * mc;
        ans %= mod;
        ans *= 2LL;
        ans %= mod;
        cout << ans << endl;
    }
}