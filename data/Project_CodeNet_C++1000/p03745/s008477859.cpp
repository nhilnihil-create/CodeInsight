#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> A) {
    ll ans = 0;
    ll before = A[0];
    bool up = false;
    bool down = false;
    rep(i, N - 1) {
        if (A[i + 1] > before) {
            if (down) {
                ans++;
                down = false;
            } else {
                up = true;
            }
        }
        if (A[i + 1] < before) {
            if (up) {
                ans++;
                up = false;
            } else {
                down = true;
            }
        }
        before = A[i + 1];
    }
    cout << ans + 1 << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
