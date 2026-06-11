#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    ll Q, H, S, D;
    cin >> Q >> H >> S >> D;
    ll N;
    cin >> N;
    ll ans;
    ll q = Q * 4;
    ll h = H * 2;
    ll s = S * 1;
    ll tmp;
    tmp = min(min(q, h), s);
    
    if (tmp * 2 < D) {
        ans = N * tmp;
    }
    else {
        ans = (N / 2) * D;
        if (N % 2 == 1) ans += tmp;
    }

    cout << ans << endl;

    return 0;
}
