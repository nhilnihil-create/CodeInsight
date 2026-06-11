#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    ll ans = 0;
    rep(i, N) ans += (B[i] - (A[i] + ans) % B[i]) % B[i];
    cout << ans << endl;
}