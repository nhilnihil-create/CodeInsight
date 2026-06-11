#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    if (N == 1) {
        if (A == B) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    ll tmp = B - A;
    ll ans = max(tmp * (N - 2) + 1, 0ll);
    cout << ans << endl;
    return 0;
}
