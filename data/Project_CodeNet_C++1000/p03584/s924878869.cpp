#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, K, k, ans = 0, s;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >>B[i];
    rep(i, 31) {
        if (i == 0) k = K;
        else k = ((K >> i) << i) - 1;
        if (k < 0) break;
        //cout << i << " " << k << endl;
        s = 0;
        rep(j, N) {
            if ((A[j] | k) == k) s += B[j];
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}