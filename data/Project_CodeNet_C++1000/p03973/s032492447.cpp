#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = A[0] - 1;
    ll k = 2;
    for (int i = 1; i < N; i++) {
        if (A[i] == k) {
            k++;
            continue;
        }
        if (A[i] % k == 0) {
            ans += A[i] / k - 1;
        } else {
            ans += A[i] / k;
        }
    }
    cout << ans << endl;
}