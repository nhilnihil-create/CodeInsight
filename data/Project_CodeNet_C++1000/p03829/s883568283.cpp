#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ll N, A, B, d;
    ll ans = 0;
    cin >> N >> A >> B;
    vector<ll>x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        if (i > 0) {
            d = x[i] - x[i-1];
            if (A*d <= B) {
                ans += A*d;
            } else {
                ans += B;
            }
        }
    }
    cout << ans << endl;
}
