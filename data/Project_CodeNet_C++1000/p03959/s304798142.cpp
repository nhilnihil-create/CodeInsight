#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;
int main() {
    int N;
    int T[100005];
    int A[100005];
    ll ans = 1;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        if (i == 0 || T[i] > T[i - 1]) {
            if (A[i] < T[i]) ans = 0;
            continue;
        }
        if (i == N - 1 || A[i] > A[i + 1]) {
            if (A[i] > T[i]) ans = 0;
            continue;
        }
        (ans *= min(A[i], T[i])) %= mod;
    }
    cout << ans << endl;
    return (0);
}