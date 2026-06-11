#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p  = pair<ll, ll>;
constexpr ll INF = 1LL << 62;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N, T;
    cin >> N >> T;
    
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    ll l = 0;
    ll r = 0;
    ll diff = 0;
    ll count = 0;
    while (r < N - 1) {
        r++;
        // cout << A[l] << ", " << A[r] << ": " << count << endl;
        if (A[l] > A[r]) {
            l = r;
        } else {
            ll d = abs(A[l] - A[r]);
            if (d > diff) {
                diff = d;
                count = 1;
            } else if (d == diff) {
                count++;
            }
        }
    }
    
    cout << count << endl;

    return 0;
}

