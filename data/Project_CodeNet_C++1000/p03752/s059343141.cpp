#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll& a : A) {
        cin >> a;
    }

    ll ans = 1e18;
    for (int i = 0; i < (1 << N); i++) {
        int n = i;
        vector<bool> visible(N, false);
        for (int j = 0; j < N; j++) {
            if (n % 2 == 0) {
                visible[j] = true;
            }
            n /= 2;
        }

        ll H = 0;
        ll cost = 0;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (visible[j]) {
                if (H >= A[j]) {
                    cost += H - A[j] + 1;
                    H++;
                }
                cnt++;
            } else {
                if (H < A[j]) {
                    cnt++;
                }
            }
            H = max(H, A[j]);
        }
        if (cnt >= K) {
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}
