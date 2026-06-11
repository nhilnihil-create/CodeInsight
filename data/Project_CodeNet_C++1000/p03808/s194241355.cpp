#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (auto &x : A) cin >> x;
    vector<ll> dif(N); dif[0] = A[0] - A[N-1];
    ll sum = A[0];
    for (int i = 1; i < N; i++) {
        sum += A[i];
        dif[i] = A[i] - A[i-1];
    }
    if (sum % (N * (N + 1) / 2) == 0) {
        ll c = sum / (N * (N + 1) / 2);
        ll t = 0;
        for (int i = 0; i < N; i++) {
            if ((c - dif[i]) % N != 0 || c < dif[i]) {
                cout << "NO" << endl;
                return 0;
            } else {
                t += (c - dif[i]) / N;
            }
        }
        if (t == c) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
