#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ll r = (ans + A[i]) % B[i];
        if (r > 0) ans += B[i] - r;
    }
    cout << ans << "\n";
}