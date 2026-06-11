#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A), greater<>());
    ll ans = 1;
    int cnt = 0;
    rep(i, N-1) {
        if (cnt < 2 && A[i] == A[i+1]) {
            ans *= A[i];
            i++;
            cnt++;
        }
    }
    if (cnt < 2) ans = 0;
    cout << ans << endl;
}