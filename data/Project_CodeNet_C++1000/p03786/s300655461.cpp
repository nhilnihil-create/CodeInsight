#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> cumsum(n, 0);
    cumsum[0] = A[0];
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i-1] + A[i];
    }

    int ans = 1;
    for (int i = n-2; i >= 0; i--) {
        if (2 * cumsum[i] >= A[i+1]) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}
